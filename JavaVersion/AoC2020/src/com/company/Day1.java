package com.company;

import java.util.ArrayList;

public class Day1 extends DefaultClass{

    public Day1()
    {
        super(1,true);
        ArrayList<Integer> input = fr.ReadInts();
        ResetClock();
        for (int i = 0; i < input.size(); i++) {
            for (int j = i+1; j < input.size(); j++) {
                if(input.get(i)+input.get(j)==2020)
                    System.out.println("Part1: "+input.get(i)*input.get(j));
            }
        }
        TimeClock();
        ResetClock();
        for (int i = 0; i < input.size()-2; i++) {
            for (int j = i+1; j < input.size()-1; j++) {
                for (int k = j+1; k < input.size(); k++) {
                    if(input.get(k)+input.get(j)+input.get(i)==2020)
                        System.out.println("Part2: "+input.get(k)*input.get(j)*input.get(i));
                }
            }
        }
        TimeClock();
    }
}
