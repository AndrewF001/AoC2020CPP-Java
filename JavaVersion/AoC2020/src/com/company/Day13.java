package com.company;

import java.util.ArrayList;

public class Day13 extends DefaultClass{

    public Day13()
    {
        super(13,true);
        ArrayList<String> lines = fr.ReadLine();
        int arrival = Integer.parseInt(lines.get(0));
        ArrayList<String> ID = fr.SplitString(lines.get(1),",");
        int BusID=0, wait=Integer.MAX_VALUE;
        for (int i = 0; i < ID.size(); i++) {
            if(!ID.get(i).equals("x"))
            {
                int div = arrival/Integer.parseInt(ID.get(i));
                int temp = Integer.parseInt(ID.get(i))  *(div+1)-arrival;
                if(temp<wait)
                {
                    wait = temp;
                    BusID = Integer.parseInt(ID.get(i));
                }
            }
        }
        System.out.println("Part1: " + (wait*BusID));
        ArrayList<Integer> first = new ArrayList<>();
        ArrayList<Integer> seconds = new ArrayList<>();
        int minute = -1;
        for (int i = 0; i < ID.size(); i++) {
            minute++;
            if(!ID.get(i).equals("x"))
            {
                first.add(Integer.parseInt(ID.get(i))-(minute%Integer.parseInt(ID.get(i))));
                seconds.add(Integer.parseInt(ID.get(i)));
            }
        }
        long timestamp = 0;
        long multiplier = seconds.get(0);
        for (int i = 1; i < first.size(); i++) {
            while((timestamp%seconds.get(i))!= first.get(i))
            {
                timestamp+=multiplier;
            }
            multiplier*=seconds.get(i);
        }
        System.out.println("Part2: "+timestamp);

    }
}
