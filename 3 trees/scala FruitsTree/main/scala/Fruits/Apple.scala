package Fruits
//weight here in constructor is a val other than the var weight shared by others
class Apple(weight:Int) extends OvalShaped {
  //we set the fruit wight to the weight entered by constructor
  setWeight(weight)

  //override functions
  override def hiFromType(): Unit = println("hi from Apple, my weight: "+ super.getWeight())
  override def toString(): String = "Apple"

}
