package Fruits

class Elderberries (weight:Int) extends  Berry {
  setWeight((weight: Int))

  override def hiFromType(): Unit = {
    println("hi from Elderberries, my Weight: " + super.getWeight())
    super.hiFromType()
  }
  override def toString(): String = "Elderberries"
}