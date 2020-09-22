using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Xml.Linq;

namespace Lab_4_327
{
    public class Program
    {
        /// <summary>
        /// Enumerates all files in a given filder recursively including the entire sub-folder hierachy.
        /// </summary>
        /// <param name="path"> the path of the directory </param>
        /// <returns> returns the current file </returns>
        static IEnumerable<string> EnumerateFilesRecursively(string path)
        {
            //enemerates through all directories
            foreach(string dir in Directory.EnumerateDirectories(path))
            {
                //for each directory it will enumerate through each file
                foreach(string file in Directory.EnumerateFiles(dir))
                {
                    yield return file;
                }
                //recursivly calls the method
                EnumerateFilesRecursively(dir);
            }
        }

        /// <summary>
        /// Computes the size of a file
        /// </summary>
        /// <param name="byteSize"> the input byte size of the file</param>
        /// <returns>returns the conversion to the right postfix</returns>
        static string FormatByteSize(long byteSize)
        {
            //byte 0 -> 999b
            if (byteSize < (long)Math.Pow(10, 3) && byteSize >= 0)
            {
                double newSize = byteSize;
                
                return newSize.ToString("n2") + "B"; //Bytes
                
            }
            //bytes 1000 -> 999999
            else if(byteSize < (long)Math.Pow(10, 6) && byteSize >= (long)Math.Pow(10, 3))
            {
                double newSize = byteSize / (double)Math.Pow(10, 3);
                
                return newSize.ToString("n2") + "kB"; //kilo bytes
                
            }
            else if (byteSize < (long)Math.Pow(10, 9) && byteSize >= (long)Math.Pow(10, 6))
            {
                double newSize = byteSize / (double)Math.Pow(10, 6);
                
                return newSize.ToString("n2") + "MB"; //mega bytes
                
            }
            else if (byteSize < (long)Math.Pow(10, 12) && byteSize >= (long)Math.Pow(10, 9))
            {
                double newSize = byteSize / (double)Math.Pow(10, 9);
                
                return newSize.ToString("n2") + "GB"; //giga bytes
                
            }
            else if (byteSize < (long)Math.Pow(10, 15) && byteSize >= (long)Math.Pow(10, 12))
            {
                double newSize = byteSize / (double)Math.Pow(10, 12);
                
                return newSize.ToString("n2") + "TB";//Tera bytes
                
            }
            else if (byteSize < (long)Math.Pow(10, 18) && byteSize >= (long)Math.Pow(10, 15))
            {
                double newSize = byteSize / (double)Math.Pow(10, 15);

                return newSize.ToString("n2") + "PB";//Peta bytes

            }
            else if (byteSize < (long)Math.Pow(10, 21) && byteSize >= (long)Math.Pow(10, 18))
            {
                double newSize = byteSize / (double)Math.Pow(10, 18);

                return newSize.ToString("n2") + "EB";//e bytes

            }
            else if (byteSize < (long)Math.Pow(10, 24) && byteSize >= (long)Math.Pow(10, 21))
            {
                double newSize = byteSize / (double)Math.Pow(10, 21);

                return newSize.ToString("n2") + "ZB";//zeta bytes

            }
            return "";
        }

        /// <summary>
        /// creates the html document
        /// </summary>
        /// <param name="files"></param>
        /// <returns></returns>
        static XDocument CreateReport(IEnumerable<string> files)
        {
            //goes through each file and groups by the extension of the file and sets the infomation for each file group g
            var query = from file in files
                        group file by Path.GetExtension(file) into g
                        select new
                        {
                            Type = g.Key,
                            Count = g.Count(),
                            Size = FormatByteSize(g.Select(f => new FileInfo(f).Length).Sum())
                        };

            //creates the table that will be replicated for each file type
            XElement table = new XElement("table", new XAttribute("border", 1),
                                                   new XElement("thead", new XElement("tr",
                                                                            new XElement("th", "Type"),
                                                                            new XElement("th", "Count"),
                                                                            new XElement("th", "Total Size"))),
                                                   new XElement("tbody",  from value in query
                                                                          select new XElement("tr", new XElement("td", value.Type),
                                                                                                    new XElement("td", new XAttribute("align", "right"),value.Count),
                                                                                                    new XElement("td", new XAttribute("align", "right"), value.Size))));

            //creates the entire report with each table inside
            XDocument report = new XDocument(new XElement("html", 
                                                new XElement("head", new XElement("title", "File Report"),
                                                                     new XElement("style", "table, th, td { border: 1px solid black; }")),
                                                                        new XElement("body",
                                                                        new XElement("td", table))));

            return report;
        }

        public static void Main(string[] args)
        {
            string input;
            string output;

            //gets the input folder name
            Console.WriteLine("Input Folder: ");
            input = "C:\\Users\\Chaz\\Desktop\\" + Console.ReadLine();

            //creates the report based on the files inside
            XDocument createReport = CreateReport(EnumerateFilesRecursively(input));

            //gets name of the output file
            Console.WriteLine("Output File name: ");
            output = "C:\\Users\\Chaz\\Desktop\\" + Console.ReadLine();

            //saves the report with the path of the file to your computer
            createReport.Save(output);

        }
    }
}
