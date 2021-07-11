package Fruits

//Fruits package shows the oop features of scala
//while the fruitsTree show the functional side of scala


//They are similar to Java 8’s interfaces
//Classes and objects can extend traits, but traits cannot be instantiated and therefore have no parameters.
trait Fruit{

  //made weight private and will use getters and setters
  private var Weight = 0
  //var is variable mutable that can change or modify it's value
  //val is a value which is immutable


  //we can have abstract and concrete method implementation
  def hiFromFruit(): Unit = println("hi from Fruit, my weight: "+ Weight)
  //****override****
  //function to be override
  def hiFromType(): Unit
  def toString(): String

  //getters and setters for weight
  def getWeight(): Int = Weight
  def setWeight(newWeight: Int): Unit = Weight = newWeight

  //operator overload
  def >(secondFruit: Fruit) = (this.getWeight() > secondFruit.getWeight())
  def <(secondFruit: Fruit) = (this.getWeight() < secondFruit.getWeight())

}
//abstract class
//not used much in 99% we use traits expect when moving from or to java abstract class ot we need constructor to be defined
// this won’t compile:  trait Fruit (weight: Int)
//if the above is a must use abstract class instead of trait



