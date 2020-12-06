package com.company;

import java.util.ArrayList;

public class Day6 extends DefaultClass{

    public Day6()
    {
        super(6,true);
        ArrayList<String> inp = fr.ReadLine();
        ArrayList<ArrayList<String>> Groups = new ArrayList<ArrayList<String>>();
        ArrayList<String> temp = new ArrayList<>();
        for (int i = 0; i < inp.size(); i++) {
            if(inp.get(i).equals(""))
            {
                Groups.add(new ArrayList<>(temp));
                temp.clear();
            }
            else
                temp.add(inp.get(i));
        }
        Groups.add(temp);
        System.out.print("File Read and format: ");
        TimeResetClock();
        Part1(Groups);
        TimeResetClock();
        Part2(Groups);
        TimeResetClock();
    }

    private void Part1(ArrayList<ArrayList<String>> Groups)
    {
        int sum = 0;
        for (int i = 0; i < Groups.size(); i++) {
            sum+=NumberOfAnswers(Groups.get(i));
        }
        System.out.println("Part1: "+ sum);
    }

    private int NumberOfAnswers(ArrayList<String> Group)
    {
        boolean letters[] = new boolean[26];
        for (int i = 0; i < Group.size(); i++) {
            for (int j = 0; j < Group.get(i).length(); j++) {
                letters[Group.get(i).charAt(j)-97]=true;
            }
        }
        int sum=0;
        for (int i = 0; i < 26; i++) {
            if(letters[i])
                sum++;
        }
        return sum;
    }

    private void Part2(ArrayList<ArrayList<String>> Groups)
    {
        int sum =0;
        for (int i = 0; i < Groups.size(); i++) {
            sum +=CollectiveAnswer(Groups.get(i));
        }
        System.out.println("Part2: "+ sum);
    }
    private int CollectiveAnswer(ArrayList<String> Group)
    {
        int letters[] = new int[26];
        for (int i = 0; i < Group.size(); i++) {
            for (int j = 0; j < Group.get(i).length(); j++) {
                letters[Group.get(i).charAt(j)-97]++;
            }
        }
        int sum=0;
        for (int i = 0; i < 26; i++) {
            if(letters[i]==Group.size())
                sum++;
        }
        return sum;
    }





}
