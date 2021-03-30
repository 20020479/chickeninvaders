#ifndef AMO_OBJECT_H_
#define AMO_OBJECT_H_
#include"COMMON_FUNCTION.h"
#include"BaseObject.h"

/*
#define WIDTH_LAZE 
#define HEIGHT_LAZE 
#define WIDTH_SPHERE 
#define HEIGHT_SPHERE 
*/



class AmoObject: public BaseObject
{
public:
	enum amotype
	{
		NONE = 0,
		LAZER = 1,
		SPHERE= 2
	};
	AmoObject();
	~AmoObject();
	void HandleInputAction(SDL_Event events);

	void HandleMove();

	int get_type() const
	{
		return amo_type_;
	}

	void set_type(const int& type)
	{
		amo_type_  = type;
	}

	bool get_is_move()const 
	{
		return is_move_;
	}

	void setwidthheight(const int& width,const int& height)
	{
		rect_.w = width;
		rect_.h = height;
	}

private:
	int x_val_;
	int y_val;
	bool is_move_;
	int amo_type_;


}




#endif