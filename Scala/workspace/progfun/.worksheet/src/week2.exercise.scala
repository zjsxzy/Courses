package week2

object exercise {;import org.scalaide.worksheet.runtime.library.WorksheetSupport._; def main(args: Array[String])=$execute{;$skip(164); 
	def factorial(n: Int): Int = {
		def loop(acc: Int, n: Int): Int =
			if (n == 0) acc
			else loop(acc * n, n - 1)
		loop(1, n)
	};System.out.println("""factorial: (n: Int)Int""");$skip(14); val res$0 = 
	factorial(4);System.out.println("""res0: Int = """ + $show(res$0));$skip(172); 
	
	def mapReduce(f: Int => Int, combine: (Int, Int) => Int, zero: Int)(a: Int, b: Int): Int =
		if (a > b) zero
		else combine(f(a), mapReduce(f, combine, zero)(a + 1, b));System.out.println("""mapReduce: (f: Int => Int, combine: (Int, Int) => Int, zero: Int)(a: Int, b: Int)Int""");$skip(91); 
  def product(f: Int => Int)(a: Int, b: Int): Int = mapReduce(f, (x, y) => x * y, 1)(a, b);System.out.println("""product: (f: Int => Int)(a: Int, b: Int)Int""");$skip(31); val res$1 = 
  
  product(x => x * x)(3, 4);System.out.println("""res1: Int = """ + $show(res$1));$skip(46); 
  
  def fact(n: Int) = product(x => x)(1, n);System.out.println("""fact: (n: Int)Int""");$skip(10); val res$2 = 
  fact(5);System.out.println("""res2: Int = """ + $show(res$2))}
}
