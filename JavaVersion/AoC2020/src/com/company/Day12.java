package com.company;

import java.util.ArrayList;

public class Day12 extends DefaultClass{

    public Day12()
    {
        super(12,true);
        int x=0,y=0;
        int facing = 1;
        ArrayList<String> inp =fr.ReadLine();
        for (int i = 0; i < inp.size(); i++) {
            int num = Integer.parseInt(inp.get(i).substring(1));
            int turn;
            switch (inp.get(i).charAt(0))
            {
                case('F'):
                    if(facing==0)
                        y+=num;
                    else if(facing==1)
                        x+=num;
                    else if(facing==2)
                        y-=num;
                    else if(facing==3)
                        x-=num;
                    break;
                case('R'):
                    turn = degreetonum(num);
                    facing+=turn;
                    if(facing>3)
                        facing-=4;
                    break;
                case('L'):
                    turn = degreetonum(num);
                    facing-=turn;
                    if(facing<0)
                        facing+=4;
                    break;
                case('N'):
                    y+=num;
                    break;
                case('S'):
                    y-=num;
                    break;
                case('E'):
                    x+=num;
                    break;
                case('W'):
                    x-=num;
                    break;
            }
        }
        System.out.println("Part1: "+(Math.abs(x)+Math.abs(y)));
        int x1=10,y1=1;
        x=0;
        y=0;
        for (int i = 0; i < inp.size(); i++) {
            int num = Integer.parseInt(inp.get(i).substring(1));
            int turn;
            switch (inp.get(i).charAt(0))
            {
                case('F'):
                    for (int j = 0; j < num; j++) {
                        x+=x1;
                        y+=y1;
                    }
                    break;
                case('R'):
                    turn = degreetonum(num);
                    if(turn == 1)
                    {
                        int temp = x1;
                        x1=y1;
                        y1=-1*temp;
                    }
                    else if(turn == 2)
                    {
                        x1*=-1;
                        y1*=-1;
                    }
                    else if(turn == 3)
                    {
                        int temp=x1;
                        x1=-1*y1;
                        y1=temp;
                    }
                    break;
                case('L'):
                    turn = degreetonum(num);
                    if(turn == 1)
                    {
                        int temp=x1;
                        x1=-1*y1;
                        y1=temp;
                    }
                    else if(turn == 2)
                    {
                        x1*=-1;
                        y1*=-1;
                    }
                    else if(turn == 3)
                    {
                        int temp = x1;
                        x1=y1;
                        y1=-1*temp;
                    }
                    break;
                case('N'):
                    y1+=num;
                    break;
                case('S'):
                    y1-=num;
                    break;
                case('E'):
                    x1+=num;
                    break;
                case('W'):
                    x1-=num;
                    break;
            }
        }
        System.out.println("Part2: "+(Math.abs(x)+Math.abs(y)));
    }

    private int degreetonum(int num)
    {
        if(num==0)
            return 0;
        if(num==90)
            return 1;
        if(num==180)
            return 2;
        if(num==270)
            return 3;
        return 0;
    }

}
