using System;
using System.Collections.Generic;

public interface IEmployeePerformance
{
    int EmployeeId { get; set; }
    int Kpi1 { get; set; }
    int Kpi2 { get; set; }
    int Kpi3 { get; set; }
    int Kpi4 { get; set; }
}
public class EmployeePerformance : IEmployeePerformance
{
    public int EmployeeId { get; set; }
    public int Kpi1 { get; set; }
    public int Kpi2 { get; set; }
    public int Kpi3 { get; set; }
    public int Kpi4 { get; set; }
}

public class EvaluateEmployeePerformance
{
    public static (List<int>, List<int>) EvaluateEmployeePerformanceHelper(EmployeePerformance[] performanceData)
    {
        List<int> continueEmployees = new List<int>();
        List<int> disengageEmployees = new List<int>();

        foreach (EmployeePerformance employee in performanceData)
        {
            int totalKpi = employee.Kpi1 + employee.Kpi2 + employee.Kpi3 + employee.Kpi4;
            int averageKpi = (int)Math.Ceiling((double)totalKpi / 4);

            if (averageKpi >= 50)
            {
                continueEmployees.Add(employee.EmployeeId);
            }
            else
            {
                disengageEmployees.Add(employee.EmployeeId);
            }
        }

        return (continueEmployees, disengageEmployees);
    }
}
public class Program
{
    public static void Main(string[] args)
    {
        int n = int.Parse(Console.ReadLine());
        EmployeePerformance[] performanceData = new EmployeePerformance[n];

        for (int i = 0; i < n; i++)
        {
            string[] input = Console.ReadLine().Split(' ');
            performanceData[i] = new EmployeePerformance
            {
                EmployeeId = int.Parse(input[0]),
                Kpi1 = int.Parse(input[1]),
                Kpi2 = int.Parse(input[2]),
                Kpi3 = int.Parse(input[3]),
                Kpi4 = int.Parse(input[4])
            };
        }

        var result = EvaluateEmployeePerformance.EvaluateEmployeePerformanceHelper(performanceData);
        List<int> continueEmployees = result.Item1;
        List<int> disengageEmployees = result.Item2;

        Console.WriteLine("Continue Employees: " + string.Join(", ", continueEmployees));
        Console.WriteLine("Disengage Employees: " + string.Join(", ", disengageEmployees));
    }
}