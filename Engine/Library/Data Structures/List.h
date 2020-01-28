#ifndef LIST_H
#define LIST_H


namespace DataStructures {
	class List
	{
	public:
		List(bool circular, bool unique);

		~List();



	private:

	};

	class LinearList : public List{

	};

	class CircularList : public List {

	};

}
#endif // !LIST_H