using System;
using System.Collections;
using System.Text;
using System.Linq;
namespace day7
{
    class Program
    {
        static void Main(string[] args)
        {
            Dictionary<string, int> dirs = new Dictionary<string, int>();
            dirs.Add("/home", 0);
            string path = "/home";
            string[] lines = System.IO.File.ReadAllLines("input.txt");
            foreach (string line in lines)
            {
                // command example:$ cd e
                // ['$', ' ', 'c', 'd', ' ', 'e']
                //   0    1    2    3    4    5
                if (line[0] == '$') // if a command
                {
                    if (line.Contains("ls"))
                    {
                        ; // pass
                    }
                    else if (line.Contains("cd"))
                    {

                        if (line[5] == '/')
                        {
                            path = "/home";
                        }
                        else if (line.Substring(5) == "..")
                        {
                            int last = path.LastIndexOf("/");
                            // exception checking
                            if (last != -1)
                            {
                                path = path.Substring(0, last);
                            }

                        }
                        else
                        {
                            string directory = line.Substring(5);
                            path = path + "/" + directory;
                            if (!dirs.ContainsKey(path))
                            {
                                if (!path.Contains("/home"))
                                {
                                    path = "/home" + path + "/" + directory;
                                }
                                dirs.Add(path, 0);
                            }
                        }

                    }

                } // end of commands

                else if (line.Substring(0, 3) == "dir")
                {
                    ; // pass

                }
                else
                {
                    int index = line.IndexOf(" ");
                    int size = int.Parse(line.Substring(0, index));
                    string directory = path.ToString();
                    int filePaths = directory.Where(x => (x == '/')).Count();

                    for (int i = 0; i < filePaths; i++)
                    {
                        Console.WriteLine("d: " + directory);
                        dirs[directory] += size;
                        int nextFileIndex = directory.LastIndexOf("/");

                        if (nextFileIndex != -1)
                        {
                            directory = directory.Substring(0, nextFileIndex);
                        }


                    }
                }
            }
            int total = 0;
            int limit = 30000000 - (70000000 - dirs["/home"]);
            var validDirectories = new List<int>();

            foreach (KeyValuePair<string, int> entry in dirs)
            {
                if (dirs[entry.Key] < 100000)
                {

                    total += dirs[entry.Key];
                }
                if (limit <= dirs[entry.Key])
                {
                    validDirectories.Add(dirs[entry.Key]);

                }
            }
            int smallest = validDirectories.Min();
            Console.WriteLine(total);
            Console.WriteLine(smallest);
        } // end of main
    }
}


