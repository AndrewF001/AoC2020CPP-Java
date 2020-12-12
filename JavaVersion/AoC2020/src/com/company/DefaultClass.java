package com.company;

public class DefaultClass {

    public String FileName;
    public FileReader fr;
    private long Start = System.currentTimeMillis();

    public DefaultClass(int day, boolean ContainsFile)
    {
        if(ContainsFile) {
            FileNameCalc(day);
            fr = new FileReader(FileName);
        }
        System.out.println("\nDay "+day + " Class running");
    }

    private void FileNameCalc(int n)
    {
        FileName = "InputFiles/input"+n+".txt";
    }

    public void ResetClock()
    {
        Start = System.currentTimeMillis();
    }

    public void TimeClock()
    {
        System.out.println(System.currentTimeMillis()-Start + " milliseconds");
    }

    public void TimeResetClock()
    {
        TimeClock();
        ResetClock();
    }

}
