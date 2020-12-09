package com.company;

import java.util.ArrayList;

public class Day9 extends DefaultClass{

    Long CyclicalArray[];
    Long Weakness;
    ArrayList<Long> inp;
    public Day9()
    {
        super(9,true);
        inp = fr.ReadLongs();
        CyclicalArray = new Long[25];
        for (int i = 0; i < 25; i++) {
            CyclicalArray[i]=inp.get(i);
        }
        int itter=0;
        for (int i = 25; i < inp.size(); i++) {
            if(IsSum(inp.get(i)))
            {
                CyclicalArray[itter]=inp.get(i);
                itter= ((itter+1)%25);
            }
            else
            {
                System.out.println("Part1: " + inp.get(i));
                Weakness = inp.get(i);
                i=inp.size();
            }
        }
        Part2();
    }

    private boolean IsSum(Long Find)
    {
        for (int i = 0; i < 25; i++) {
            if(CyclicalArray[i]<Find) {
                for (int j = 0; j < 25; j++) {
                    if(i!=j)
                    {
                        if(CyclicalArray[i]+CyclicalArray[j]==Find)
                            return true;
                    }
                }
            }
        }
        return false;
    }

    void Part2()
    {
        long sum=0;
        long smallest=0,largest=0;
        for (int i = 0; i < inp.size(); i++) {
            sum=inp.get(i);
            smallest=sum;
            largest=sum;
            for (int j = i+1; j < inp.size(); j++) {
                sum+= inp.get(j);
                if(sum==Weakness)
                {
                    System.out.println("Part2: "+(smallest+largest));
                    j=inp.size();
                    i=inp.size();
                }
                else if(sum>Weakness)
                {
                    j=inp.size();
                }
                else
                {
                    if(inp.get(j)>largest)
                        largest=inp.get(j);
                    else if(inp.get(j)<smallest)
                        smallest=inp.get(j);
                }
            }
        }
    }
}
