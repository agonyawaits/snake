//  Desk.cpp
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#include "Desk.h"
#include "Config.hpp"
#include "Object.hpp"
#include <ncurses.h>

Desk::Desk( Object& t_char,
            Object& t_food,
            int& t_score )
    : m_height( Config::deskHeight ), m_width( Config::deskWidth ),
    m_char( t_char ), m_food( t_food ), m_score( t_score ) {}

void Desk::draw( WINDOW* window ) const {
    box( window, 0, 0 );

    m_char.draw( window );
    m_food.draw( window );
    mvprintw( m_height+1, 0, "Score: %d", m_score );
}

void Desk::update( const int& t_playerInput ) const {
    onInput( t_playerInput );
    m_char.update();

    if ( m_food.getX() == m_char.getX() && 
        m_food.getY() == m_char.getY() )
    {
        m_food.update();
        m_char.extend();
    }

    m_score = m_char.size() * 10;
}

void Desk::onInput( const int& t_playerInput ) const {
    m_char.onInput( t_playerInput );
}