package org.ubillos.javier.oddManOut
import scala.io.Source
import scala.collection.mutable.HashMap

object Main{
	def main(args: Array[String]) {
		val fileName = "res/A-large-practice.in"
		val inFile = Source.fromFile(fileName)
      
		// Get number of cases
		val noCases = Source.fromFile(fileName).getLine(1).toInt 
		var currLine = 1;
  
		for( i <- 0.until(noCases)) {
			print("Case #"+(i+1)+": ")
			currLine = 2 + i*2
			var noGuests = Source.fromFile(fileName).getLine(currLine).toInt
			var guests = Source.fromFile(fileName).getLine(currLine+1).split(' ')
    
			var guestMap = new HashMap[Long, Int]
   
			for( no <- guests) {
				//print(no )
				if(guestMap contains no.toLong)
					guestMap(no.toLong)  += 1
				else
					guestMap += (no.toLong) -> 1
				//print(":"+guestMap(no.toLong)+", ")
			}
			//println()
   
			for ((guest, count) <- guestMap)
				if( 1 == count) println(guest)
			
		} 
  

	}
}




