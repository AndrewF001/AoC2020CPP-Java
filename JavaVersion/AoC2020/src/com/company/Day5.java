package com.company;

import java.util.ArrayList;

public class Day5 extends DefaultClass {

    public Day5()
    {
        super(5,true);
        System.out.println(BinarySearch("BBBBBBB",0,127));
        System.out.println(BinarySearch("FFFFFFF",0,127));
        boolean[][] plane = new boolean[128][8];
        ArrayList<String> inp = fr.ReadLine();
        ArrayList<String> Rowinp = new ArrayList<>();
        ArrayList<String> Colluminp = new ArrayList<>();
        for (int i = 0; i < inp.size(); i++) {
            Rowinp.add(inp.get(i).substring(0,7));
            Colluminp.add(inp.get(i).substring(7));
            Colluminp.set(i,Colluminp.get(i).replace('R','B'));
            Colluminp.set(i,Colluminp.get(i).replace('L','F'));
        }
        for (int i = 0; i < inp.size(); i++) {
            plane[BinarySearch(Rowinp.get(i),0,127 )][BinarySearch(Colluminp.get(i),0,7)] = true;
        }
        for (int i = 127; i > -1; i--) {
            for (int j = 7; j > -1; j--) {
                if(plane[i][j])
                {
                    System.out.println("Part1: " + (i*8+j));
                    j=-1;
                    i=-1;
                }
            }
        }
        boolean pass=true;
        for (int i = 0; i < 127; i++) {
            for (int j = 0; j < 8; j++) {
                if(!plane[i][j]&&!pass) {
                    System.out.println("Part2: " + (i * 8 + j));
                    i=128;
                    j=8;
                }
                else if(plane[i][j])
                    pass=false;
            }
        }
    }

    private int BinarySearch(String str, int min, int max)
    {
        if(str.charAt(0)=='F')
        {
            max -= (max-min)/2+1;
            if(str.length()==1)
                return max;
            else
                return BinarySearch(str.substring(1),min,max);
        }
        else if(str.charAt(0)=='B')
        {
            min += (max-min)/2+1;
            if(str.length()==1)
                return max;
            else
                return BinarySearch(str.substring(1),min,max);
        }
        return -1;
    }
}
