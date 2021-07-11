package Fruits

class Avocado(weight:Int) extends OvalShaped {
  setWeight(weight)

  override def hiFromType(): Unit = println("hi from Avocado, my Weight: "  + super.getWeight())

  override def toString(): String = "Avocado"

}
