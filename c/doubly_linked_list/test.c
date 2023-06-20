#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Song
{
	char title[100];
	char artist[100];
	struct Song *prev;
	struct Song *next;
} Song;

typedef struct Playlist
{
	Song *head;
	Song *tail;
} Playlist;

void init(Playlist *playlist)
{
	playlist->head = NULL;
	playlist->tail = NULL;
}

void add_song(Playlist **playlists, const char *title, const char *artist)
{
	char firstchar = title[0];
	int index = -1;

	if (firstchar >= 'a' && firstchar <= 'z')
		index = firstchar - 'a';
	else if (firstchar >= 'A' && firstchar <= 'Z')
		index = firstchar - 'A';
	else
		return;
	if (index >= 0 && index < 26)
	{
		Playlist *playlist = playlists[index];

		Song *new_song = (Song *)malloc(sizeof(Song));
		strcpy(new_song->title, title);
		strcpy(new_song->artist, artist);
		new_song->prev = NULL;
		new_song->next = NULL;

		if (playlist->head == NULL)
		{
			playlist->head = new_song;
			playlist->tail = new_song;
		}
		else
		{
			playlist->tail->next = new_song;
			new_song->prev = playlist->tail;
			playlist->tail = new_song;
		}
	}
}

void print_playlist(const Playlist *playlist)
{
	Song *curr = playlist->head;

	while (curr != NULL)
	{
		printf("%s - %s\n", curr->title, curr->artist);
		curr = curr->next;
	}
}

void free_playlist(Playlist *playlist)
{
	Song *curr = playlist->head;
	Song *next;

	while (curr != NULL)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	playlist->head = NULL;
	playlist->tail = NULL;
}

void remove_song(Playlist **playlists, const char *title)
{
	char song_title = title[0];
	int index = -1;

	if (song_title >= 'a' && song_title <= 'z')
		index = song_title - 'a';
	else if (song_title >= 'A' && song_title <= 'Z')
		index = song_title - 'A';
	else
		return;

	if (index >= 0 && index < 26)
	{
		Playlist *playlist = playlists[index];
		Song *curr = playlist->head;

		while (curr != NULL)
		{
			if (strcmp(curr->title, title) == 0)
			{
				if (curr->prev == NULL) // 삭제할 노래가 첫번째 노래일 경우
				{
					playlist->head = curr->next;
					if (playlist->head != NULL)
						playlist->head->prev = NULL;
				}
				else if (curr->next == NULL) // 삭제할 노래가 마지막 노래일 경우
				{
					playlist->tail = curr->prev;
					if (playlist->tail != NULL)
						playlist->tail->next = NULL;
				}
				else // 삭제할 노래가 중간에 있을 경우
				{
					curr->prev->next = curr->next;
					curr->next->prev = curr->prev;
				}

				free(curr);
				return;
			}

			curr = curr->next;
		}
	}
}

int main()
{
	Playlist *playlists[26];
	for (int i = 0; i < 26; i++)
	{
		playlists[i] = (Playlist *)malloc(sizeof(Playlist));
		init(playlists[i]);
	}

	add_song(playlists, "Stay", "The Kid LAROI & Justin Bieber");
	add_song(playlists, "Bad Habits", "Ed Sheeran");
	add_song(playlists, "bbb", "Ed Sheeran");
	add_song(playlists, "Industry Baby", "Lil Nas X & Jack Harlow");
	add_song(playlists, "Fancy Like", "Walker Hayes");
	add_song(playlists, "Kiss Me More", "Doja Cat Featuring SZA");
	add_song(playlists, "Levitating", "Dua Lipa");
	add_song(playlists, "Montero (Call Me By Your Name)", "Lil Nas X");

	// for (int i = 0; i < 26; i++)
	// {
	// 	printf("%c List:\n", 'a' + i);
	// 	print_playlist(playlists[i]);
	// 	printf("\n");
	// }

	printf("current playlist\n");
	for (int i = 0; i < 26; i++)
	{
		if (playlists[i]->head != NULL)
		{
			printf("%c List:\n", 'a' + i);
			print_playlist(playlists[i]);
			printf("\n");
		}
	}

	remove_song(playlists, "bbb");

	printf("\n\n\nafter remove bbb\n");
	for (int i = 0; i < 26; i++)
	{
		if (playlists[i]->head != NULL)
		{
			printf("%c List:\n", 'a' + i);
			print_playlist(playlists[i]);
			printf("\n");
		}
	}

	for (int i = 0; i < 26; i++)
	{
		free_playlist(playlists[i]);
		free(playlists[i]);
	}

	return 0;
}
