import week3._

object scratch {;import org.scalaide.worksheet.runtime.library.WorksheetSupport._; def main(args: Array[String])=$execute{;$skip(52); val res$0 = 
	new Rational(1, 2);System.out.println("""res0: week3.Rational = """ + $show(res$0));$skip(49); 
	
	def error(msg: String) = throw new Error(msg);System.out.println("""error: (msg: String)Nothing""");$skip(16); 
	
	val x = null;System.out.println("""x  : Null = """ + $show(x ));$skip(19); 
	val y: String = x;System.out.println("""y  : String = """ + $show(y ))}

}
