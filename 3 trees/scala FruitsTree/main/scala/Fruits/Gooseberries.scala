package Fruits

class Gooseberries(weight:Int) extends  Berry {
  setWeight((weight: Int))

  override def hiFromType(): Unit = {
    println("hi from Gooseberries, my Weight: " + super.getWeight())
    super.hiFromType()
  }
  override def toString(): String = "Blackberries"
}
