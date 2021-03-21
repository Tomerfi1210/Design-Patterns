//#include <string>
//#include <ostream>
//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//class CodeBuilder
//{
//private:
//    const string& m_class_name;
//    vector<pair<string, string>> attr;
//public:
//    CodeBuilder(const string& class_name) : m_class_name(class_name)
//    {
//        // todo
//    }
//
//    CodeBuilder& add_field(const string& name, const string& type)
//    {
//        attr.emplace_back(make_pair(type, name));
//        return *this;
//    }
//
//    friend ostream& operator<<(ostream& os, const CodeBuilder& obj)
//    {
//        string indent(2, ' ');
//        os << "class " << obj.m_class_name << endl
//            << "{\n";
//
//        for (auto& att : obj.attr)
//            os << indent << att.first << " " << att.second << ";\n";
//
//        os << "};\n";
//        return os;
//    }
//};
//
//
////--------------------------------------------------------------------------------------------------------------
//
//
////another example
//#include <string>
//#include <iostream>
//#include <memory>
//using namespace std;
//
//// "Product"
//class Pizza_Product
//{
//public:
//	void setDough(const string& dough) { m_dough = dough; }
//	void setSauce(const string& sauce) { m_sauce = sauce; }
//	void setTopping(const string& topping) { m_topping = topping; }
//
//	void taste() const
//	{
//		cout << "Pizza with " << m_dough << " dough, "
//			<< m_sauce << " sauce and "
//			<< m_topping << " topping. Mmm." << endl;
//	}
//private:
//	string m_dough;
//	string m_sauce;
//	string m_topping;
//};
//
//// "Abstract Builder"
//class Pizza_Builder
//{
//public:
//	virtual ~Pizza_Builder() {};
//
//	Pizza_Product* getPizza() { return m_pizza.release(); }
//
//	void createNewPizzaProduct()
//	{
//		m_pizza = make_unique<Pizza_Product>();
//	}
//	virtual void buildDough() = 0;
//	virtual void buildSauce() = 0;
//	virtual void buildTopping() = 0;
//protected:
//	unique_ptr<Pizza_Product> m_pizza;
//};
//
////----------------------------------------------------------------
//
//class Margherita_ConcreteBuilder : public Pizza_Builder
//{
//public:
//	virtual ~Margherita_ConcreteBuilder() {};
//
//	virtual void buildDough()
//	{
//		m_pizza->setDough("cross");
//	}
//	virtual void buildSauce()
//	{
//		m_pizza->setSauce("tomato");
//	}
//	virtual void buildTopping()
//	{
//		m_pizza->setTopping("mozzarela+basil");
//	}
//};
//
//class Spicy_ConcreteBuilder : public Pizza_Builder
//{
//public:
//	virtual ~Spicy_ConcreteBuilder() {};
//
//	virtual void buildDough()
//	{
//		m_pizza->setDough("pan baked");
//	}
//	virtual void buildSauce()
//	{
//		m_pizza->setSauce("tomato+chilli");
//	}
//	virtual void buildTopping()
//	{
//		m_pizza->setTopping("pepperoni+salami");
//	}
//};
//
////----------------------------------------------------------------
//
//class Cook_Director
//{
//public:
//	void tastePizza()
//	{
//		m_pizzaBuilder->getPizza()->taste();
//	}
//	void makePizza(Pizza_Builder* pb)
//	{
//		m_pizzaBuilder = pb;
//		m_pizzaBuilder->createNewPizzaProduct();
//		m_pizzaBuilder->buildDough();
//		m_pizzaBuilder->buildSauce();
//		m_pizzaBuilder->buildTopping();
//	}
//private:
//	Pizza_Builder* m_pizzaBuilder;
//};
//
//int main()
//{
//	// Example 1
//    auto cb = CodeBuilder{ "Person" }.add_field("name", "string").add_field("age", "int");
//    cout << cb << endl;
//
//
//
//    // Example 2
//	Cook_Director 				cook;
//	Margherita_ConcreteBuilder 	margheritaBuilder;
//	Spicy_ConcreteBuilder    	spicyPizzaBuilder;
//
//	cook.makePizza(&margheritaBuilder);
//	cook.tastePizza();
//
//	cook.makePizza(&spicyPizzaBuilder);
//	cook.tastePizza();
//
//    return 0;
//}