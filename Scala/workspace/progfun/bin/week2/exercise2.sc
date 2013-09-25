package week2

object exercise2 {
	def product(f: Int => Int)(a: Int, b: Int): Int =
		if (a > b) 1
		else f(a) * product(f)(a + 1, b)
	product(x => x * x)(3, 4)
	
	def fact(n: Int) = product(x => x)(1, n)
	fact(5)
	

		
	def sum(f: Int => Int, a: Int, b: Int) = {
		def loop(a: Int, acc: Int): Int =
			if (a > b) acc
			else loop(a + 1, f(a) + acc)
		loop(a, 0)
	}
	sum(x => x * x, 3, 5)
}