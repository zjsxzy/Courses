package week2

object exercise2 {;import org.scalaide.worksheet.runtime.library.WorksheetSupport._; def main(args: Array[String])=$execute{;$skip(134); 
	def product(f: Int => Int)(a: Int, b: Int): Int =
		if (a > b) 1
		else f(a) * product(f)(a + 1, b);System.out.println("""product: (f: Int => Int)(a: Int, b: Int)Int""");$skip(27); val res$0 = 
	product(x => x * x)(3, 4);System.out.println("""res0: Int = """ + $show(res$0));$skip(44); 
	
	def fact(n: Int) = product(x => x)(1, n);System.out.println("""fact: (n: Int)Int""");$skip(9); val res$1 = 
	fact(5);System.out.println("""res1: Int = """ + $show(res$1));$skip(152); 
	

		
	def sum(f: Int => Int, a: Int, b: Int) = {
		def loop(a: Int, acc: Int): Int =
			if (a > b) acc
			else loop(a + 1, f(a) + acc)
		loop(a, 0)
	};System.out.println("""sum: (f: Int => Int, a: Int, b: Int)Int""");$skip(23); val res$2 = 
	sum(x => x * x, 3, 5);System.out.println("""res2: Int = """ + $show(res$2))}
}
