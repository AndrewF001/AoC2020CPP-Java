package com.company;

import java.util.ArrayList;

public class Day8 extends DefaultClass{

    private int acc=0;
    private ArrayList<String> Lines;
    private ArrayList<String> Instr;
    private ArrayList<Integer> Opper;

    public Day8()
    {
        super(8,true);
        Lines = fr.ReadLine();
        Instr = new ArrayList<>();
        Opper = new ArrayList<>();
        for (int i = 0; i < Lines.size(); i++) {
            ArrayList<String> split = fr.SplitString(Lines.get(i)," ");
            Instr.add(split.get(0));
            Opper.add(Integer.parseInt(split.get(1)));
        }
        int header=0;
        boolean visited[] = new boolean[Lines.size()];
        while(!visited[header])
        {
            visited[header]=true;
            if(Instr.get(header).equals("acc"))
            {
                acc+= Opper.get(header);
                header++;
            }
            else if(Instr.get(header).equals("jmp"))
            {
                header+=Opper.get(header);
            }
            else
            {
                header++;
            }
        }
        System.out.println("Part1:" + acc);
        Part2();
    }

    private void Part2()
    {
        boolean Term=false;
        for (int i = 0; i < Opper.size(); i++) {
            ArrayList<Integer> op = new ArrayList<>(Opper);
            ArrayList<String> ins = new ArrayList<>(Instr);
            if(ins.get(i).equals("jmp")) {
                ins.set(i, "nop");
                Term = DidTerminate(op,ins);
            }
            else if(ins.get(i).equals("nop")) {
                ins.set(i, "jmp");
                Term = DidTerminate(op,ins);
            }
            if(Term)
            {
                System.out.println("Part2: " + acc);
                i=Opper.size();
            }

        }
    }

    private boolean DidTerminate(ArrayList<Integer>opp,ArrayList<String>inst)
    {
        int header=0;
        acc=0;
        boolean visited[] = new boolean[Lines.size()];
        while(!visited[header]&&header<Lines.size()-1)
        {
            visited[header]=true;
            if(inst.get(header).equals("acc"))
            {
                acc+= opp.get(header);
                header++;
            }
            else if(inst.get(header).equals("jmp"))
            {
                header+=opp.get(header);
            }
            else
            {
                header++;
            }
        }
        if(header==Lines.size()-1)
            return true;
        else
            return false;
    }
}
