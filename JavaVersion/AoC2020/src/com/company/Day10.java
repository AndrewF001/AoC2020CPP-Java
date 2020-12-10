package com.company;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;

public class Day10 extends DefaultClass{

    ArrayList<Integer> Adpaters;
    public Day10()
    {
        super(10,true);
        Adpaters = fr.ReadInts();
        Collections.sort(Adpaters);
        int current = 0,ones=0,threes=1;
        ResetClock();
        for (int i = 0; i < Adpaters.size(); i++) {
            if(Adpaters.get(i)-current==1)
                ones++;
            else if(Adpaters.get(i)-current==3)
                threes++;
            current = Adpaters.get(i);
        }
        System.out.println("Part1: " +(ones*threes) );
        TimeResetClock();
        Part2();
        TimeClock();
    }

    private void Part2()
    {
        long ways = 1;
        int Current=0;
        int concurrentones = 0;
        for (int i = 0; i < Adpaters.size(); i++) {
            if(Adpaters.get(i)-Current==1)
            {
                concurrentones++;
                Current=Adpaters.get(i);
            }
            else if(Adpaters.get(i)-Current==3)
            {
                Current=Adpaters.get(i);
                concurrentones--;
                if(concurrentones>0)
                {
                    //ways*= factorial(concurrentones);
                    long x = (long) Math.pow(2,concurrentones);
                    if(concurrentones>2)
                        x-=concurrentones-2;
                    ways*=x;

                }
                concurrentones=0;
            }
        }
        concurrentones--;
        if(concurrentones>0)
        {
            //ways*= factorial(concurrentones)+1;
            long x = (long) Math.pow(2,concurrentones);
            if(concurrentones>2)
                x-=concurrentones-2;
            ways*=x;
        }
        System.out.println("Part2: "+ways);
    }

    private long factorial(int n)
    {
        long sum=1;
        for (int i = 2; i <= n; i++) {
            sum*=i;
        }
        return sum;
    }

    private long NumSolutions(int ConCurrent)
    {
        long sum[] = {2,4,6,10,16};
        return sum[ConCurrent-1];
    }
}
