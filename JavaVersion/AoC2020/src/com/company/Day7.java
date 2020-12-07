package com.company;

import java.util.ArrayList;

public class Day7 extends DefaultClass {

    ArrayList<Rule> Rules = new ArrayList<>();
    ArrayList<String> LookFor = new ArrayList<>();
    ArrayList<String> NextLookFor = new ArrayList<>();
    public Day7()
    {
        super(7,true);
        ArrayList<String> inp = fr.ReadLine();
        for (int i = 0; i < inp.size(); i++) {
            Rules.add(new Rule(inp.get(i)));
        }
        System.out.println("File Read and Translate: ");
        TimeResetClock();
        Part1();
        TimeResetClock();
        Part2();
        TimeClock();
    }

    private void Part1()
    {
        LookFor.add("shinygold");
        int sum =0;
        while(!LookFor.isEmpty())
        {
            for (int i = 0; i < Rules.size(); i++) {
                if(!Rules.get(i).Added)
                {
                    sum+=RuleContainBag(i);
                }
            }
            LookFor = new ArrayList<>(NextLookFor);
            NextLookFor.clear();
        }
        System.out.println("Part1: "+ sum);
    }

    private int RuleContainBag(int i)
    {
        for (int j = 0; j < Rules.get(i).ContainBag.size(); j++) {
            for (int k = 0; k < LookFor.size(); k++) {
                if(Rules.get(i).ContainBag.get(j).equals(LookFor.get(k)))
                {
                    NextLookFor.add(Rules.get(i).OutBag);
                    Rules.get(i).Added=true;
                    return 1;
                }
            }
        }
        return 0;
    }

    private void Part2()
    {
        int sum = NumberBags("shinygold");
        System.out.println("Part2:" + sum);
    }

    private int NumberBags(String BagName)
    {
        int sum = 0;
        for (int i = 0; i < Rules.size(); i++) {
            if(Rules.get(i).OutBag.equals(BagName))
            {
                if(Rules.get(i).ContainBag.size()==0)
                    return 0;
                for (int j = 0; j < Rules.get(i).ContainBag.size(); j++) {
                    sum += Rules.get(i).NumContainBag.get(j) * (NumberBags(Rules.get(i).ContainBag.get(j))+1);
                }
            }
        }
        return sum;
    }

    private class Rule
    {
        public String OutBag;
        public ArrayList<String> ContainBag = new ArrayList<>();
        public ArrayList<Integer> NumContainBag = new ArrayList<>();
        public boolean Added = false;

        public Rule(String str)
        {
            ArrayList<String> Split = fr.SplitString(str," ");
            OutBag = Split.get(0);
            OutBag += Split.get(1);
            for (int i = 4; i < Split.size(); i++) {
                try {
                    NumContainBag.add(Integer.parseInt(Split.get(i)));
                    i++;
                    ContainBag.add(Split.get(i));
                    i++;
                    ContainBag.set(ContainBag.size() - 1, ContainBag.get(ContainBag.size() - 1) + Split.get(i));
                    i++;
                }
                catch (Exception e)
                {
                    i=Split.size()+1;
                }
            }
        }
    }
}
