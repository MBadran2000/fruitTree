package Fruits

class Blackberries(weight:Int) extends  TinyFruit  with Berry {
  setWeight((weight: Int))

  //deadly diamond in scala
  //scala solved The diamond problem (multiple inheritance) using Traits, which are similar to Java interfaces
  //Scala does not support inheritance from multiple classes, but a user can extend multiple traits in a single class:
  override def hiFromType(): Unit = {
    println("hi from Blackberries, my Weight: " + super.getWeight())
    super.hiFromType()
  }

  //Blackberries -> Berry -> TinyFruit -> Fruit -> AnyRef -> Any

  override def toString(): String = "Blackberries"
}

//
////test blackberries
//object demo{
//  def main(args: Array[String]): Unit = {
//    var blackberry = new Blackberries(2);
//    blackberry.hiFromType()
//  }
//}