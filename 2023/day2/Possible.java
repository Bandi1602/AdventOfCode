import java.util.ArrayList;
import java.util.List;

public class Possible 
{
    public static int IsPossible(String s)
    {
        String[] adott_jatek = s.split("; "); //3 blue, 4 red || 1 red, 2 green, 6 blue || 2 green
        int kek = 0;
        int piros = 0;
        int zold = 0;

        int flag = 1;

            for (String jatek : adott_jatek) // 3 blue, 4 red
            {
                String[] game = jatek.split(", ");


                for (String adott : game) // 3 blue
                {   

                    if (adott.split(" ")[1].equals("blue")) 
                    {   
                        kek = Integer.parseInt(adott.split(" ")[0]);
                    }

                    if (adott.split(" ")[1].equals("red")) 
                    {
                        piros = Integer.parseInt(adott.split(" ")[0]);
                    }

                    if (adott.split(" ")[1].equals("green")) 
                    {
                        zold = Integer.parseInt(adott.split(" ")[0]);
                    }
                }

                if (piros > 12 || zold > 13 || kek > 14 ) 
                {   
                    flag = 0;
                }

                kek = 0;
                piros = 0;
                zold = 0;
            }

            
        return flag;
    }

    public static List<Integer> minSzinekSzama(String s)
    {
        String[] adott_jatek = s.split("; "); //3 blue, 4 red || 1 red, 2 green, 6 blue || 2 green
        int kek = 0;
        int piros = 0;
        int zold = 0;

        List<Integer> res = new ArrayList<>();

        for (String jatek : adott_jatek) // 3 blue, 4 red
        {
            String[] game = jatek.split(", ");


            for (String adott : game) // 3 blue
            {   

                if (adott.split(" ")[1].equals("blue")) 
                {   int tmp = Integer.parseInt(adott.split(" ")[0]);

                    if (tmp >= kek) 
                    {
                        kek = tmp;
                    }
                }

                if (adott.split(" ")[1].equals("red")) 
                {
                    int tmp = Integer.parseInt(adott.split(" ")[0]);

                    if (tmp >= piros) 
                    {
                        piros = tmp;
                    }
                }

                if (adott.split(" ")[1].equals("green")) 
                {
                    int tmp = Integer.parseInt(adott.split(" ")[0]);

                    if (tmp >= zold) 
                    {
                        zold = tmp;
                    }
                }
            }
        }

        res.add(piros);
        res.add(zold);
        res.add(kek);

        return res;
    }
}
