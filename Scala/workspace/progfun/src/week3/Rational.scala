package week3

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