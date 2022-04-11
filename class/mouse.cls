#class	mouse_interface

;** mouse event management 

public	common dcl status%
public	common dcl type%
public	common dcl button%
public	common dcl column%
public	common dcl line%

;* activate the flow of mouse events

public	inline constructor start_mouse:
	status = Event(0)
end

;* disactivate the flow of mouse events

public	inline destructor stop_mouse:
	status = Event(7)
end

public	inline method get_mouse_mask: Event(5) End

public	inline method set_mouse_mask:(value%)
	Event(5) = value
end

public	routine method flush_mouse:
	status = Event(6)
end

public	routine method get_mouse_event:
	type = Event(1)
	button = Event(2)
	column = Event(3)
	line = Event(4)
end

#endclass

