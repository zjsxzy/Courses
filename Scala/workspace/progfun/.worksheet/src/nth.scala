import week4._

object nth {;import org.scalaide.worksheet.runtime.library.WorksheetSupport._; def main(args: Array[String])=$execute{;$skip(118); 
  def nth[T](n: Int, xs: List[T]): T =
  	if (n == 0) xs.head
  	else nth(n - 1, xs.tail);System.out.println("""nth: [T](n: Int, xs: week4.List[T])T""");$skip(64); 
  	
  val list = new Cons(1, new Cons(2, new Cons(3, new Nil)));System.out.println("""list  : week4.Cons[Int] = """ + $show(list ))}
}
