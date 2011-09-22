package org.ubillos.javier.scalatest

import scala.io.Source

object IntValue {
	def apply(x: Int) = x.toString
	def unapply(x: AnyRef ): Option[Int] =x match {
	  case s:String => try { Some(s.toInt) } catch { case _ => None } 
	  case _ => None
   }

}

object Parser {
  def parse(line: String) {
	var prevNr: Int = -1
    for( c:Char  <- line){

    	
    	c match {

    	  case 'a' => if(prevNr == 2) print(" ")
    	  			  print("2")
    	  			  prevNr = 2
    	  case 'b' => if(prevNr == 2) print(" ")
    	  			  print("22")
    	  			  prevNr = 2
    	  case 'c' => if(prevNr == 2) print(" ")
    	  			  print("222")
    	  			  prevNr = 2
    	  case 'd' => if(prevNr == 3) print(" ")
    	  			  print("3")
    	  			  prevNr = 3
    	  case 'e' => if(prevNr == 3) print(" ")
    	  			  print("33")
    	  			  prevNr = 3
    	  case 'f' => if(prevNr == 3) print(" ")
    	  			  print("333")
    	  			  prevNr = 3
    	  case 'g' => if(prevNr == 4) print(" ")
    	  			  print("4")
    	  			  prevNr = 4
    	  case 'h' => if(prevNr == 4) print(" ")
    	  			  print("44")
    	  			  prevNr = 4
    	  case 'i' => if(prevNr == 4) print(" ")
    	  			  print("444")
    	  			  prevNr = 4
    	  case 'j' => if(prevNr == 5) print(" ")
    	  			  print("5")
    	  			  prevNr = 5
    	  case 'k' => if(prevNr == 5) print(" ")
    	  			  print("55")
    	  			  prevNr = 5
    	  case 'l' => if(prevNr == 5) print(" ")
    	  			  print("555")
    	  			  prevNr = 5
    	  case 'm' => if(prevNr == 6) print(" ")
    	  			  print("6")
    	  			  prevNr = 6
    	  case 'n' => if(prevNr == 6) print(" ")
    	  			  print("66")
    	  			  prevNr = 6
    	  case 'o' => if(prevNr == 6) print(" ")
    	  			  print("666")
    	  			  prevNr = 6
    	  case 'p' => if(prevNr == 7) print(" ")
    	  			  print("7")
    	  			  prevNr = 7
    	  case 'q' => if(prevNr == 7) print(" ")
    	  			  print("77")
    	  			  prevNr = 7
    	  case 'r' => if(prevNr == 7) print(" ")
    	  			  print("777")
    	  			  prevNr = 7
    	  case 's' => if(prevNr == 7) print(" ")
    	  			  print("7777")
    	  			  prevNr = 7
    	  case 't' => if(prevNr == 8) print(" ")
    	  			  print("8")
    	  			  prevNr = 8
    	  case 'u' => if(prevNr == 8) print(" ")
    	  			  print("88")
    	  			  prevNr = 8
    	  case 'v' => if(prevNr == 8) print(" ")
    	  			  print("888")
    	  			  prevNr = 8
    	  case 'w' => if(prevNr == 9) print(" ")
    	  			  print("9")
    	  			  prevNr = 9
    	  case 'x' => if(prevNr == 9) print(" ")
    	  			  print("99")
    	  			  prevNr = 9
    	  case 'y' => if(prevNr == 9) print(" ")
    	  			  print("999")
    	  			  prevNr = 9
    	  case 'z' => if(prevNr == 9) print(" ")
    	  			  print("9999")
    	  			  prevNr = 9
    	  case ' ' =>if(prevNr == 0) print(" ")
    	  			  print("0")
    	  			  prevNr = 0
    	  case _ => ""
    	}
    	
    	
    }
    println()
  } 
  
}

object Main {
    def main(args: Array[String]) {
      val inFile = Source.fromFile("res/C-large-practice.in")
      
      // Get number of lines
      var lines = Source.fromFile("res/C-large-practice.in").getLine(1).toInt

      for( i <- 0.until(lines)){
    	  print( "Case #"+(i+1)+": ")
    	  var line = inFile.getLine(i+2)
    	  Parser.parse(line)
      }
      
    }	
}
