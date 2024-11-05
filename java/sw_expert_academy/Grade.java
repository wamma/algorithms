import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

public class Grade {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        HashMap<String, Double> gradeMap = new HashMap<>();
        gradeMap.put("A+", 4.5);
        gradeMap.put("A", 4.0);
        gradeMap.put("B+", 3.5);
        gradeMap.put("B", 3.0);
        gradeMap.put("C+", 2.5);
        gradeMap.put("C", 2.0);
        gradeMap.put("D+", 1.5);
        gradeMap.put("D", 1.0);
        gradeMap.put("F", 0.0);

        try {
            String[] grades = br.readLine().trim().split(" ");
            double total = 0.0;
            int count = 0;

            for (String grade : grades) {
                if (gradeMap.containsKey(grade)) {
                    total += gradeMap.get(grade);
                    count++;
                }
            }
            if (count > 0) {
                double average = total / count;
                System.out.printf("평균 학점은: %.2f\n", average);
            } else {
                System.out.println("점수를 입력해야 합니다.");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
