#ifndef AMO_OBJECT_H_
#define AMO_OBJECT_H_
#define WIDTH_LAZE 35
#define HEIGHT_LAZE 5
#define WIDTH_SPHERE 10
#define HEIGHT_SPHERE 10

#include"BaseObject.h"
enum AmoType()
{
	NONE = 0;
	LAZE = 1;
	SPHERE = 2;
};

class AmoObject:public BaseObject
{
public:
	AmoObject();
	~AmoObject();
	void HandleMove();
	void HandleInputAction(SDL_Event events);
	int get_type() const{return amo_type_;}
	void set_type(const int& type) {amo_type_ = type;}
	bool get_is_move() const {return is_move_;}
	void set_is_move(bool is_move){is_move_ = is_move;}
	void SetWidthHeight(const int& height, const int& width){ rect_.w = width; rect_.h = height;};
private:
	int x_val_;
	int y_val_;
	bool is_move_;
	int amo_type_;
};
#endif
