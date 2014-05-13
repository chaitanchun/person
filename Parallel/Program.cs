using System;
using System.Collections.Generic;
using System.Collections.Concurrent;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Threading.Tasks.Dataflow;

namespace Parallel
{
    class Program
    {
        #region Data Parallel
        static void DataParallel()
        {
            // Set up matrices. Use small values to better view  
            // result matrix. Increase the counts to see greater  
            // speedup in the parallel loop vs. the sequential loop. 
            int colCount = 180;
            int rowCount = 2000;
            int colCount2 = 270;
            double[,] m1 = InitializeMatrix(rowCount, colCount);
            double[,] m2 = InitializeMatrix(colCount, colCount2);
            double[,] result = new double[rowCount, colCount2];

            // First do the sequential version.
            Console.WriteLine("Executing sequential loop...");
            Stopwatch stopwatch = new Stopwatch();
            stopwatch.Start();

            MultiplyMatricesSeq(m1, m2, result);
            stopwatch.Stop();
            Console.WriteLine("Sequential loop time in milliseconds: {0}", stopwatch.ElapsedMilliseconds);

            // For the skeptics.
            OfferToPrint(rowCount, colCount2, result);

            // Reset timer and results matrix. 
            stopwatch.Reset();
            result = new double[rowCount, colCount2];

            // Do the parallel loop.
            Console.WriteLine("Executing parallel loop...");
            stopwatch.Start();
            MultiplyMatricesPara(m1, m2, result);
            stopwatch.Stop();
            Console.WriteLine("Parallel loop time in milliseconds: {0}", stopwatch.ElapsedMilliseconds);
            OfferToPrint(rowCount, colCount2, result);

            // Keep the console window open in debug mode.
            Console.WriteLine("Press any key to exit.");
            Console.ReadKey();
        }

        static void MultiplyMatricesSeq(double[,] matA, double[,] matB, double[,] result)
        {
            int aRow = matA.GetLength(0);
            int aCol = matA.GetLength(1);
            int bCol = matB.GetLength(1);
            for (int i = 0; i < aRow; i++)
            {
                for (int k = 0; k < bCol; k++)
                {
                    for (int j = 0; j < aCol; j++)
                    {
                        result[i, k] += matA[i, j] + matB[j, k];
                    }
                }
            }
        }

        static void MultiplyMatricesPara(double[,] matA, double[,] matB, double[,] result)
        {
            int aRow = matA.GetLength(0);
            int aCol = matA.GetLength(1);
            int bCol = matB.GetLength(1);
            System.Threading.Tasks.Parallel.For(0, aRow, i =>
                {
                    for (int k = 0; k < bCol; k++)
                    {
                        double temp = 0;
                        for (int j = 0; j < aCol; j++)
                        {
                            temp += matA[i, j] + matB[j, k];
                        }
                        result[i, k] = temp;
                    }

                });
        }

        static double[,] InitializeMatrix(int rows, int cols)
        {
            double[,] matrix = new double[rows, cols];

            Random r = new Random();
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    matrix[i, j] = r.Next(100);
                }
            }
            return matrix;
        }

        private static void OfferToPrint(int rowCount, int colCount, double[,] matrix)
        {
            Console.WriteLine("Computation complete. Print results? y/n");
            char c = Console.ReadKey().KeyChar;
            if (c == 'y' || c == 'Y')
            {
                Console.WindowWidth = 180;
                Console.WriteLine();
                for (int x = 0; x < rowCount; x++)
                {
                    Console.WriteLine("ROW {0}: ", x);
                    for (int y = 0; y < colCount; y++)
                    {
                        Console.Write("{0:#.##} ", matrix[x, y]);
                    }
                    Console.WriteLine();
                }

            }
        }
        #endregion

        private static void Run()
        {
            StopLoop();
            BreakAtThreshold();

            Console.WriteLine("Press any key to exit.");
            Console.ReadKey();
        }

        private static void StopLoop()
        {
            Console.WriteLine("Stop loop...");
            double[] source = MakeDemoSource(1000, 1);
            ConcurrentStack<double> results = new ConcurrentStack<double>();

            // i is the iteration variable. loopState is a  
            // compiler-generated ParallelLoopState
            System.Threading.Tasks.Parallel.For(0, source.Length, (i, loopState) =>
            {
                // Take the first 100 values that are retrieved 
                // from anywhere in the source. 
                if (i < 100)
                {
                    // Accessing shared object on each iteration 
                    // is not efficient. See remarks. 
                    double d = Compute(source[i]);
                    results.Push(d);
                }
                else
                {
                    loopState.Stop();
                    return;
                }

            } // Close lambda expression.
            ); // Close Parallel.For

            Console.WriteLine("Results contains {0} elements", results.Count());
        }


        static void BreakAtThreshold()
        {
            double[] source = MakeDemoSource(10000, 1.0002);
            ConcurrentStack<double> results = new ConcurrentStack<double>();

            // Store all values below a specified threshold.
            System.Threading.Tasks.Parallel.For(0, source.Length, (i, loopState) =>
            {
                double d = Compute(source[i]);
                results.Push(d);
                if (d > .2)
                {
                    // Might be called more than once!
                    loopState.Break();
                    Console.WriteLine("Break called at iteration {0}. d = {1} ", i, d);
                    Thread.Sleep(1000);
                }
            });

            Console.WriteLine("results contains {0} elements", results.Count());
        }

        static double Compute(double d)
        {
            //Make the processor work just a little bit. 
            return Math.Sqrt(d);
        }


        // Create a contrived array of monotonically increasing 
        // values for demonstration purposes.  
        static double[] MakeDemoSource(int size, double valToFind)
        {
            double[] result = new double[size];
            double initialval = .01;
            for (int i = 0; i < size; i++)
            {
                initialval *= valToFind;
                result[i] = initialval;
            }

            return result;
        }

        static void ThreadLocalVar()
        {
            int[] nums = Enumerable.Range(0, 1000000).ToArray();
            long total = 0;

            // Use type parameter to make subtotal a long, not an int
            System.Threading.Tasks.Parallel.For<long>(0, nums.Length, () => 0, (j, loop, subtotal) =>
            {
                subtotal += nums[j];
                return subtotal;
            },
                (x) => Interlocked.Add(ref total, x)
            );

            Console.WriteLine("The total is {0}", total);
            Console.WriteLine("Press any key to exit");
            Console.ReadKey();
        }

        static void FirstTask()
        {
            Thread.CurrentThread.Name = "main";
            Task task = new Task(() => Console.WriteLine("this is task A!"));
            task.Start();
            Console.WriteLine("this is current thread {0}", Thread.CurrentThread.Name);
            task.Wait();
            Console.ReadKey();
        }

        static void ContinuTasks()
        {
            var getData = Task.Factory.StartNew(() =>
            {
                Random rnd = new Random();
                int[] values = new int[100];
                for (int ctr = 0; ctr <= values.GetUpperBound(0); ctr++)
                    values[ctr] = rnd.Next();

                return values;
            });
            var processData = getData.ContinueWith((x) =>
            {
                int n = x.Result.Length;
                long sum = 0;
                double mean;

                for (int ctr = 0; ctr <= x.Result.GetUpperBound(0); ctr++)
                    sum += x.Result[ctr];

                mean = sum / (double)n;
                return Tuple.Create(n, sum, mean);
            });
            var displayData = processData.ContinueWith((x) =>
            {
                return String.Format("N={0:N0}, Total = {1:N0}, Mean = {2:N2}",
                                     x.Result.Item1, x.Result.Item2,
                                     x.Result.Item3);
            });
            Console.WriteLine(displayData.Result);
            Console.ReadKey();
        }

        static void ParentTasks()
        {
            Task parent = Task.Factory.StartNew(() =>
            {
                Console.WriteLine("parent task is started!");
                for (int i = 0; i < 10; i++)
                {
                    int num = i;
                    Task.Factory.StartNew((x) =>
                    {
                        Thread.SpinWait(5000000);
                        Console.WriteLine("Attach child #{0}", x);
                    }, num, TaskCreationOptions.AttachedToParent);
                }
            });
            parent.Wait();
            Console.WriteLine("parent is finished.");
            Console.ReadKey();
        }

        static void BufferBlock()
        {
            var bufBlock = new BufferBlock<int>();
            for (int i = 0; i < 4; i++)
            {
                bufBlock.Post(i);
            }
            for (int i = 0; i < 4; i++)
                Console.WriteLine("value: {0}", bufBlock.Receive());

            var broadcast = new BroadcastBlock<double>(null);
            broadcast.Post(Math.PI);
            for (int i = 0; i < 4; i++)
                Console.WriteLine("value: {0}", broadcast.Receive());

            broadcast.Post(9.88947349);
            Thread.Sleep(500);
            for (int i = 0; i < 4; i++)
                Console.WriteLine("value: {0}", broadcast.Receive());

            var writeBlock = new WriteOnceBlock<int>(null);
            System.Threading.Tasks.Parallel.Invoke(
                () => writeBlock.Post(1),
                () => writeBlock.Post(2),
                () => writeBlock.Post(3));
            Console.WriteLine("value is {0}", writeBlock.Receive());
            Console.ReadKey();
        }

        static void TestActionBlock()
        {
            ActionBlock<int> action = new ActionBlock<int>(n=> Console.WriteLine("value : {0}", n));

            for (int i = 0; i < 4; i++)
            {
                action.Post(i);
            }
            action.Complete();
            action.Completion.Wait();

            var block = new TransformManyBlock<string, char>(s => s.ToCharArray());
            block.Post("tanchun");
            block.Post("chai");
            for (int i = 0; i < ("tanchunchai").Length; i++)
            {
                Console.WriteLine(block.Receive());
            }
            Console.ReadKey();
        }

        static void GroupBlock()
        {
            var batchBlock = new BatchBlock<int>(10);
            for (int i = 0; i < 14; i++)
            {
                batchBlock.Post(i);
            }
            batchBlock.Complete();
            Console.WriteLine("the sum is {0}", batchBlock.Receive().Sum());
            Console.WriteLine("the sum is {0}", batchBlock.Receive().Sum());

            var joinBlock = new JoinBlock<int, int, char>();
            joinBlock.Target1.Post(3);
            joinBlock.Target1.Post(4);
            joinBlock.Target2.Post(3);
            joinBlock.Target2.Post(4);
            joinBlock.Target3.Post('+');
            joinBlock.Target3.Post('-');
            for (int i = 0; i < 2; i++)
            {
                var data = joinBlock.Receive();
                switch (data.Item3)
                {
                    case '+':
                        Console.WriteLine("{0} + {1} = {2}", data.Item1, data.Item2, data.Item1 + data.Item2);
                        break;
                    case '-':
                        Console.WriteLine("{0} - {1} = {2}", data.Item1, data.Item2, data.Item1 - data.Item2);
                        break;
                    default:
                        break;
                }
                
            }
            Console.ReadKey();
        }

        static void Main(string[] args)
        {
            DataParallel();
            Run();
            ThreadLocalVar();
            FirstTask();
            ContinuTasks();
            ParentTasks();
            BufferBlock();
            TestActionBlock();
            GroupBlock();
        }
    }
}
