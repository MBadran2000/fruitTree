package Fruits

trait OvalShaped extends Fruit {
  override def hiFromType(): Unit = println("hi from Oval Shaped Fruit")
  override def toString(): String = "OvalShaped"

}
