import java.util.List;

public class day2_1 
{
    public static void main(String[] args)
    {
        List<String> sorok =FileUtils.readLines("input.txt");

        int possible = 0;
        boolean tmp ;

        for (String sor : sorok) 
        {   

            int index = sor.indexOf(":") + 2;
            String res = sor.substring(index);//3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green

            if (Possible.IsPossible(res) == 1)
            {
                possible += Integer.parseInt(sor.split(": ")[0].split(" ")[1]);
            }
        }
        System.out.printf("Possible games: %d\n", possible);
    }
}