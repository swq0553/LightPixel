�}O
  �  ��� �8ҭ    ��� �~*�}��O����w,B��*�kP��%x���vFRL �O236R�\<��d$��b~풦�עa|D��Ul�a�;�9����#2K����k�n���/�� �'�����?H\.�M�ͣ�UC���UMe�*A+����@�/�S���� �"�f��	���D	�׵�s��t�I+\@��tN���8����{�3��xn��b8]�p-�rKa�6�u�n�J�.����Ţ�t	�m�/��%�����v��}f����>B�K�9�xK���}B��4�>w�̝����p��e�5�CJ��<�g�؅�|�p��?8��]Qh2�^ +)�U��G|��e��v{�zp��Y>���᰻��X������b���bBr�Տ��X78�n1Kl$���7#�:27w���#r��+oN&�GE̿T1Y]M�9�5� ��;p��2��`Rֱ�lX�ǉ(M9Y[��,���S�n���	WindowPtr MakeWindow(std::string const & name, int w, int h, bool full_screen);

	void Update();
	void UpdateStats();
private:
	virtual void OnCreate()	{}
	virtual void OnDestroy(){}
	virtual void OnSuspend(){}
	virtual void OnResume() {}

	//virtual void DoUpdateOverlay() = 0;
	virtual uint32_t DoUpdate() = 0;
protected:
	std::string mName;
	WindowPtr   mMain_wnd;
};

