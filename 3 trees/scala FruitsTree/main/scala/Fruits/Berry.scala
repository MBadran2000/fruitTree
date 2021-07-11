package Fruits

trait Berry extends Fruit{
  override def hiFromType(): Unit =println("hi from Berry")
  override def toString(): String = "Berry"
}
