package Fruits

trait LargeFruit extends Fruit {
  override def hiFromType(): Unit = println("hi from Large Fruit")
  override def toString(): String = "LargeFruit"
}
