package com.company;

import java.util.ArrayList;

public class Day3 extends DefaultClass {

    public Day3()
    {
        super(3,true);
        ArrayList<String> Input = fr.ReadLine();
        ResetClock();
        System.out.println("Part1: " + TreeEncounter(3,1,Input));
        TimeClock();
        ResetClock();
        long sum = TreeEncounter(1,1,Input);
        sum*=TreeEncounter(3,1,Input);
        sum*=TreeEncounter(5,1,Input);
        sum*=TreeEncounter(7,1,Input);
        sum*=TreeEncounter(1,2,Input);
        System.out.println("Part2: "+sum);
        TimeClock();
    }

    private int TreeEncounter(int right, int down,ArrayList<String> Input)
    {
        int x=0;
        int sum=0;
        for (int i = 0; i < Input.size(); i+=down) {
            if(Input.get(i).charAt(x)=='#')
                sum++;
            x=(x+right)%Input.get(0).length();
        }
        return sum;
    }
}
