import java.util.List;

public class day2_2 
{
    public static void main(String[] args)
    {
        List<String> sorok =FileUtils.readLines("input.txt");

        int possible = 0;

        for (String sor : sorok) 
        {   

            int index = sor.indexOf(":") + 2;
            String res = sor.substring(index);//3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green

            //System.out.println(Possible.minSzinekSzama(res));

            possible = possible + Possible.minSzinekSzama(res).get(0) * Possible.minSzinekSzama(res).get(1) * Possible.minSzinekSzama(res).get(2);
        }
        System.out.printf("Possible games: %d\n", possible);
    }
}