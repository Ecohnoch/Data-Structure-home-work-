#ifndef SKIP_LIST_H_
#define SKIP_LIST_H_

struct skip_list_node;

class skip_list
{
	public:
		explicit skip_list(int max_level = 12);
		~skip_list();

		int insert(int data);
		bool find(int data) const;
		int remove(int data);
		int size() const;

	private:
		int rand_level();

	private:
		skip_list_node *header_;
		int size_;
		int max_level_;

	private:
		skip_list(const skip_list&);
		skip_list& operator= (const skip_list&);
};


#endif
