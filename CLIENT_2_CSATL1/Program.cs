using ATL1Lib;

var atl = new CoVar8();
Console.WriteLine($"7 / 2 = {atl.Fun81(7, 2)}");
Console.WriteLine($"6 * 2 * 4 = {atl.Func82(6, 2, 4)}");
atl.Func83(7.5d, out double referenced);
Console.WriteLine($"6 referenced by ATL, returned: {referenced}");
Console.ReadKey();
