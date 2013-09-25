package week3

object rationals {;import org.scalaide.worksheet.runtime.library.WorksheetSupport._; def main(args: Array[String])=$execute{;$skip(62); 
  val x = new Rational(1, 2);System.out.println("""x  : week3.Rational = """ + $show(x ));$skip(29); 
  val y = new Rational(5, 7);System.out.println("""y  : week3.Rational = """ + $show(y ));$skip(29); 
  val z = new Rational(3, 2);System.out.println("""z  : week3.Rational = """ + $show(z ));$skip(12); val res$0 = 
 	x - y - z;System.out.println("""res0: week3.Rational = """ + $show(res$0));$skip(8); val res$1 = 
 	y + y;System.out.println("""res1: week3.Rational = """ + $show(res$1));$skip(8); val res$2 = 
  x < y;System.out.println("""res2: Boolean = """ + $show(res$2));$skip(10); val res$3 = 
  x max z;System.out.println("""res3: week3.Rational = """ + $show(res$3))}
 

  
}

class Rational(x: Int, y: Int) {
	require(y != 0, "denominator must be nonzero")
	
	def this(x: Int) = this(x, 1)
	
	private def gcd(a: Int, b: Int): Int = if (b == 0) a else gcd(b, a % b)
	def numer = x
	def denom = y
	
	def < (that: Rational) = numer * that.denom < that.numer * denom
	
	def max(that: Rational) = if (this < that) that else this
	
	def + (that: Rational) =
		new Rational(
			numer * that.denom + that.numer * denom,
			denom * that.denom)
	
	def addRational(r: Rational, s: Rational): Rational =
		new Rational(
			r.numer * s.denom + s.numer * r.denom,
			r.denom * s.denom)
			
	def unary_- : Rational = new Rational(-numer, denom)
	
	def - (that: Rational) = this + -that
			
	override def toString = {
		val g = gcd(numer, denom)
		numer / g + "/" + denom / g
	}
}
