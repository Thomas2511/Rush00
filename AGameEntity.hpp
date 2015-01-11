#ifndef AGAMEENTITY_HPP
# define AGAMEENTITY_HPP

#include "Position.hpp"
#include "Hitbox.hpp"
#include "Sprite.hpp"
#include "AList.hpp"
#include <iostream>
#include <sstream>

class AGameEntity : public AList
{
	public:
		AGameEntity(int x, int y, int wdth, int hght, int speed, Sprite const & sprite);
		AGameEntity(AGameEntity const & src);
		virtual ~AGameEntity( void );

		AGameEntity &			operator=(AGameEntity const & rhs);

		Position const &		getPosition(void) const;
		Hitbox const &			getHitbox(void) const;
		Sprite const &			getSprite(void) const;
		int						getSpeed() const;

		virtual void			refresh() = 0;
		virtual void			destroy(void) = 0;

		std::string				toString(void) const;

	protected:
		Position				_pos;
		Hitbox					_hb;
		Sprite					_sp;
		int						_dead;
		int						_speed;
		int						_maxspeed;
		int						_index;
		AGameEntity( void );

	private:
		static unsigned int		_nb_inst;
};

std::ostream &					operator<<(std::ostream & o, AGameEntity const & rhs);

#endif /* AGAMEENTITY_HPP */
