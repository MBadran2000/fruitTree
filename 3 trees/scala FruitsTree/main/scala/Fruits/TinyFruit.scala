package Fruits

trait TinyFruit extends Fruit {
  override def hiFromType(): Unit = println("hi from Tiny Fruit")
  override def toString(): String = "TinyFruit"
}
