package com.company;

import java.util.ArrayList;

public class Day11 extends DefaultClass{

    char[][] grid;

    public Day11()
    {
        super(11,true);
        ResetClock();
        ArrayList<String> lines = fr.ReadLine();
        grid = new char[lines.size()][lines.get(0).length()];
        for (int i = 0; i < lines.size(); i++) {
            for (int j = 0; j < lines.get(0).length(); j++) {
                if(lines.get(i).charAt(j)=='L')
                    grid[i][j] = '#';
                else
                    grid[i][j]='.';
            }
        }

        while(simulation());
        int sum=0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if(grid[i][j]=='#')
                    sum++;
            }
        }
        System.out.println("Part1: "+sum);
        TimeResetClock();

        for (int i = 0; i < lines.size(); i++) {
            for (int j = 0; j < lines.get(0).length(); j++) {
                if(lines.get(i).charAt(j)=='L')
                    grid[i][j] = '#';
                else
                    grid[i][j]='.';
            }
        }

        while(simulationpart2());
        sum=0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if(grid[i][j]=='#')
                    sum++;
            }
        }
        System.out.println("Part2: "+sum);
        TimeResetClock();
    }

    private boolean simulationpart2()
    {
        boolean Change = false;
        char[][] grid2 = new char[grid.length][grid[0].length];
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                grid2[i][j]=grid[i][j];
            }
        }
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if(grid[i][j]=='L')
                {
                    if(ChangeLPart2(j,i))
                    {
                        Change=true;
                        grid2[i][j]='#';
                    }
                }
                else if(grid[i][j]=='#')
                {
                    if(ChangehashPart2(j,i))
                    {
                        Change=true;
                        grid2[i][j]='L';
                    }
                }
            }
        }
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                grid[i][j]=grid2[i][j];
            }
        }
        return Change;
    }

    private boolean ChangeLPart2(int x, int y)
    {
        for (int i = x-1; i > -1; i--) {
            if(grid[y][i]=='#')
                return false;
            else if(grid[y][i]=='L')
                i=-1;
        }
        for (int i = x+1; i < grid[0].length; i++) {
            if(grid[y][i]=='#')
                return false;
            else if(grid[y][i]=='L')
                i=grid[0].length;
        }
        for (int i = y-1; i > -1; i--) {
            if(grid[i][x]=='#')
                return false;
            else if(grid[i][x]=='L')
                i=-1;
        }
        for (int i = y+1; i < grid.length; i++) {
            if(grid[i][x]=='#')
                return false;
            else if(grid[i][x]=='L')
                i=grid.length;
        }
        boolean reached = false;
        int x1=x-1,y1=y-1;
        while(!reached)
        {
            try
            {
                if(grid[y1][x1]=='#')
                    return false;
                else if(grid[y1][x1]=='L') {
                    reached = true;
                }
                x1-=1;
                y1-=1;
            }
            catch (Exception E) {
                reached = true;
            }
        }
        reached = false;
        x1=x-1;
        y1=y+1;
        while(!reached)
        {
            try
            {
                if(grid[y1][x1]=='#')
                    return false;
                else if(grid[y1][x1]=='L') {
                    reached = true;
                }
                x1-=1;
                y1+=1;
            }
            catch (Exception E) {
                reached = true;
            }
        }
        reached = false;
        x1=x+1;
        y1=y-1;
        while(!reached)
        {
            try
            {
                if(grid[y1][x1]=='#')
                    return false;
                else if(grid[y1][x1]=='L') {
                    reached = true;
                }
                x1+=1;
                y1-=1;
            }
            catch (Exception E) {
                reached = true;
            }
        }
        reached = false;
        x1=x+1;
        y1=y+1;
        while(!reached)
        {
            try
            {
                if(grid[y1][x1]=='#')
                    return false;
                else if(grid[y1][x1]=='L') {
                    reached = true;
                }
                x1+=1;
                y1+=1;
            }
            catch (Exception E) {
                reached = true;
            }
        }
        return true;
    }

    private boolean ChangehashPart2(int x, int y)
    {
        int sum =0;
        for (int i = x-1; i > -1; i--) {
            if(grid[y][i]=='#') {
                sum++;
                i=-1;
            }
            else if(grid[y][i]=='L')
                i=-1;
        }
        for (int i = x+1; i < grid[0].length; i++) {
            if(grid[y][i]=='#') {
                sum++;
                i=grid[0].length;
            }
            else if(grid[y][i]=='L')
                i=grid[0].length;
        }
        for (int i = y-1; i > -1; i--) {
            if(grid[i][x]=='#') {
                sum++;
                i=-1;
            }
            else if(grid[i][x]=='L')
                i=-1;
        }
        for (int i = y+1; i < grid.length; i++) {
            if(grid[i][x]=='#') {
                sum++;
                i=grid.length;
            }
            else if(grid[i][x]=='L')
                i=grid.length;
        }
        boolean reached = false;
        int x1=x-1,y1=y-1;
        while(!reached)
        {
            try
            {
                if(grid[y1][x1]=='#') {
                    sum++;
                    reached=true;
                }
                else if(grid[y1][x1]=='L') {
                    reached = true;
                }
                x1-=1;
                y1-=1;
            }
            catch (Exception E) {
                reached = true;
            }
        }
        reached = false;
        x1=x-1;
        y1=y+1;
        while(!reached)
        {
            try
            {
                if(grid[y1][x1]=='#') {
                    sum++;
                    reached=true;
                }
                else if(grid[y1][x1]=='L') {
                    reached = true;
                }
                x1-=1;
                y1+=1;
            }
            catch (Exception E) {
                reached = true;
            }
        }
        reached = false;
        x1=x+1;
        y1=y-1;
        while(!reached)
        {
            try
            {
                if(grid[y1][x1]=='#') {
                    sum++;
                    reached=true;
                }
                else if(grid[y1][x1]=='L') {
                    reached = true;
                }
                x1+=1;
                y1-=1;
            }
            catch (Exception E) {
                reached = true;
            }
        }
        reached = false;
        x1=x+1;
        y1=y+1;
        while(!reached)
        {
            try
            {
                if(grid[y1][x1]=='#') {
                    sum++;
                    reached=true;
                }
                else if(grid[y1][x1]=='L') {
                    reached = true;
                }
                x1+=1;
                y1+=1;
            }
            catch (Exception E) {
                reached = true;
            }
        }
        return sum>4;
    }

    private boolean simulation()
    {
        boolean Change = false;
        char[][] grid2 = new char[grid.length][grid[0].length];
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                grid2[i][j]=grid[i][j];
            }
        }
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if(grid[i][j]=='L')
                {
                    if(ChangeL(j,i))
                    {
                        Change=true;
                        grid2[i][j]='#';
                    }
                }
                else if(grid[i][j]=='#')
                {
                    if(Changehash(j,i))
                    {
                        Change=true;
                        grid2[i][j]='L';
                    }
                }
            }
        }
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                grid[i][j]=grid2[i][j];
            }
        }
        return Change;
    }

    private boolean ChangeL(int x, int y)
    {
        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                try
                {
                    if(grid[y+i][x+j]=='#')
                        return false;
                }
                catch (Exception e)
                {

                }
            }
        }
        return true;
    }

    private boolean Changehash(int x, int y)
    {
        int sum=0;
        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                try
                {
                    if(grid[y+i][x+j]=='#')
                        sum++;
                }
                catch (Exception e)
                {

                }
            }
        }
        return sum>4;
    }

}
