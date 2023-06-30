#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>
#include <stdlib.h>

#define HASH_TABLE_SIZE 100

typedef struct s_entry
{
	wchar_t word[50];
	wchar_t translation[50];
	struct s_entry *next;
} t_entry;

t_entry *dictionary[HASH_TABLE_SIZE] = {0};

unsigned int hash_function(const wchar_t *word)
{
	unsigned int hash = 0;
	for (int i = 0; word[i] != L'\0'; ++i)
		hash = 31 * hash + word[i];
	return hash % HASH_TABLE_SIZE;
}

void insert_word(const wchar_t *word, const wchar_t *translation)
{
	unsigned int index = hash_function(word);
	t_entry *new = (t_entry *)malloc(sizeof(t_entry));
	if (new == NULL)
	{
		printf("메모리 할당에 실패했습니다.\n");
		return;
	}
	wcscpy(new->word, word);
	wcscpy(new->translation, translation);
	new->next = dictionary[index];
	dictionary[index] = new;
}

const wchar_t *translate(const wchar_t *word)
{
	unsigned int index = hash_function(word);
	t_entry *entry = dictionary[index];
	while (entry != NULL)
	{
		if (wcscmp(entry->word, word) == 0)
			return entry->translation;
		entry = entry->next;
	}
	return L"단어를 찾을 수 없습니다.";
}

int main(int argc, char **argv)
{
	setlocale(LC_ALL, ""); // 유니코드 지원을 위해 로케일 설정

	if (argc < 2)
	{
		printf("사용법: ./a.out [번역하고자 하는 단어]\n");
		return 1;
	}
	FILE *file = fopen("dictionary.txt", "r");
	if (file == NULL)
	{
		printf("파일을 열 수 없습니다.\n");
		return 1;
	}
	wchar_t line[100];
	while (fgetws(line, sizeof(line) / sizeof(line[0]), file) != NULL) // 파일에서 한 줄씩 읽어서 해시 테이블에 저장
	{
		wchar_t *word;
		wchar_t *translation;
		wchar_t *tmp;

		word = wcstok(line, L",\n", &tmp); // 쉼표와 개행 문자를 기준으로 단어와 뜻을 분리, word에는 단어가, tmp에는 뜻이 저장됨
		translation = wcstok(tmp, L",\n", &tmp); // tmp에 저장된 뜻을 다시 쉼표와 개행 문자를 기준으로 단어와 뜻을 분리, translation에는 뜻이 저장됨
		insert_word(word, translation);
	}
	fclose(file);

	wchar_t korean_word[50];
	mbstowcs(korean_word, argv[1], strlen(argv[1]) + 1);

	const wchar_t *english_word = translate(korean_word);
	wprintf(L"%ls: %ls\n", korean_word, english_word);

	return 0;
}
