#pragma once


namespace PlantillaCLR {

	bool k_up=		false, 
		k_down=		false, 
		k_left=		false, 
		k_right=	false,
		k_space=	false,
		k_z=		false,
		shoot=		false,
		door1=		true,
		jumped=		false;
	void TabulaRaza();
	void BackImage		(int,int,int,int,int,int,int,int,int,int);	//(sprite ptr, Bitmap width, Bitmap height, x pos, y pos, image x, image y,image width,image height)
	short colid[900*600];
	int excolor=0x00000000, sindex0=0, StaticPosY=64,StaticPosX=0,stimer=0,sdelay=5,scale=3,bulx=0,buly=0,salto=0;
	int surf=0,dir=1;

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;				//inicializa componentes para los sonidos

	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
		InitializeComponent();			
		bufferGAMB=gcnew Bitmap(900,600,System::Drawing::Imaging::PixelFormat::Format32bppRgb);
		Samus1=gcnew Bitmap("Samus1.bmp");
		Bullet=gcnew Bitmap("Bullet.bmp");
		Samus2=gcnew Bitmap("Samus2.bmp");
		background=gcnew Bitmap("Back.bmp");
		Door=gcnew Bitmap("Puertas.bmp");
		}
	public: 
		Bitmap^ bufferGAMB;
		Bitmap^ Samus1;
		Bitmap^ background;
		Bitmap^ Door;
		Bitmap^ Samus2;
		Bitmap^ Bullet;

	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	protected:
		/// <summary>
		/// Limpiar los recursos que se estén utilizando.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::ComponentModel::IContainer^  components;
	protected: 
	private:
#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::WindowFrame;
			this->pictureBox1->Cursor = System::Windows::Forms::Cursors::Cross;
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(900, 600);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 40;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(692, 37);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(94, 85);
			this->textBox1->TabIndex = 1;
			this->textBox1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::key_down);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->label1->Location = System::Drawing::Point(784, 622);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(61, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"                  ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label2->Location = System::Drawing::Point(868, 606);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(14, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"^";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label3->Location = System::Drawing::Point(849, 622);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(50, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"< | v | >";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::SystemColors::HotTrack;
			this->label6->Location = System::Drawing::Point(630, 622);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(150, 13);
			this->label6->TabIndex = 7;
			this->label6->Text = L"Espacio para cambiar de color";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::SystemColors::HotTrack;
			this->label7->Location = System::Drawing::Point(751, 606);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(111, 13);
			this->label7->TabIndex = 8;
			this->label7->Text = L"Flechas para moverse";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackColor = System::Drawing::SystemColors::ControlText;
			this->ClientSize = System::Drawing::Size(900, 640);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->textBox1);
			this->ForeColor = System::Drawing::SystemColors::Control;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MinimumSize = System::Drawing::Size(256, 240);
			this->Name = L"Form1";
			this->Text = L"Da Metroid Evolution";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e){
				SoundPlayer^ Musica=gcnew SoundPlayer();
				Musica->SoundLocation="M1_Brinstar_Loop.wav";
				Musica-> PlayLooping();
			 }
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
				 if (k_up==1){if(jumped==0&&salto>32){jumped=1;k_up=0;}else{salto+=4;} }
				 if (StaticPosX<160-32&&StaticPosY<60||StaticPosX>160-32&&StaticPosY<138)StaticPosY+=8;
				 if(jumped==0) {salto+=4;StaticPosY+=4;}
					if(StaticPosY>140) StaticPosY=140;
					if(StaticPosX<160-32&&StaticPosY>61&&StaticPosY<90)StaticPosY=61; 
					
					if(salto>0&&jumped==1){StaticPosY+=-4;salto+=-4;}else{jumped=0;}
					if(StaticPosX<0)StaticPosX=0;
				 RenderGAMB();
				 SwapBufferGAMB();
				 
			 }

	private: System::Void RenderGAMB()
			 {
//Rectangulo
				Rectangle rect = Rectangle(0,0,bufferGAMB->Width,bufferGAMB->Height);
					System::Drawing::Imaging::BitmapData^ bmpData = bufferGAMB->LockBits( rect, 
					System::Drawing::Imaging::ImageLockMode::ReadWrite, bufferGAMB->PixelFormat ); //Crean un .bmp sobre el cual vamos a dibujar
					IntPtr ptr = bmpData->Scan0;//Pasa la direccion del primer pixel de la imagen a una variable tipo IntPtr
					surf= static_cast<int>(ptr.ToInt32());
//Samus
				Rectangle rect2 = Rectangle(0,0,Samus1->Width,Samus1->Height);
				   	System::Drawing::Imaging::BitmapData^ bmpData2 = Samus1->LockBits( rect2, 
					System::Drawing::Imaging::ImageLockMode::ReadWrite,System::Drawing::Imaging::PixelFormat::Format32bppRgb);
					IntPtr ptr2 = bmpData2->Scan0;
//Fondo
				Rectangle rect1 = Rectangle(0,0,background->Width,background->Height);
				   	System::Drawing::Imaging::BitmapData^ bmpData1 = background->LockBits( rect1, 
					System::Drawing::Imaging::ImageLockMode::ReadWrite,System::Drawing::Imaging::PixelFormat::Format32bppRgb);
					IntPtr sprFondo = bmpData1->Scan0;
//puerta 
				Rectangle rect3 = Rectangle(0,0,Door->Width,Door->Height);
				   	System::Drawing::Imaging::BitmapData^ bmpData3 = Door->LockBits( rect3, 
					System::Drawing::Imaging::ImageLockMode::ReadWrite,System::Drawing::Imaging::PixelFormat::Format32bppRgb);
					IntPtr ptr3 = bmpData3->Scan0;
					
//Samus numero 2 
				Rectangle rect4 = Rectangle(0,0,Samus2->Width,Samus2->Height);
				   	System::Drawing::Imaging::BitmapData^ bmpData4 = Samus2->LockBits( rect4, 
					System::Drawing::Imaging::ImageLockMode::ReadWrite,System::Drawing::Imaging::PixelFormat::Format32bppRgb);
					IntPtr ptr4 = bmpData4->Scan0;

//Bullet
				Rectangle rect5 = Rectangle(0,0,Bullet->Width,Bullet->Height);
				   	System::Drawing::Imaging::BitmapData^ bmpData5 = Bullet->LockBits( rect5, 
					System::Drawing::Imaging::ImageLockMode::ReadWrite,System::Drawing::Imaging::PixelFormat::Format32bppRgb);
					IntPtr ptr5 = bmpData5->Scan0;

				   TabulaRaza();
					BackImage	(static_cast<int>(sprFondo.ToInt32()),background->Width,background->Height,
								66,0,
								StaticPosX,StaticPosY, 
								256,224,
								0x00000000);
					if (dir==1)
					BackImage	(static_cast<int>(ptr2.ToInt32()),Samus1->Width,		Samus1->Height,	
								128*scale,96*scale,		//X,Y
								0,sindex0*32,			//Image X,Image Y
								20,32					//Display Size W,H
								,0xff0080ff);			//Color transparente
					else
					BackImage	(static_cast<int>(ptr4.ToInt32()),Samus2->Width,		Samus2->Height,	
								128*scale,96*scale,		//X,Y
								0,sindex0*32,			//Image X,Image Y
								20,32					//Display Size W,H
								,0xff0080ff);			//Color transparente
					if (shoot==1) {
						if (bulx>64*scale){shoot=0;}bulx+=25;
						if ((138+(bulx*dir))*scale>(492-StaticPosX)*scale)door1=0;
						BackImage	(static_cast<int>(ptr5.ToInt32()),Bullet->Width,		Bullet->Height,			//bala
								138*scale+(bulx*dir),108*scale,		//X,Y
								0,0,								//Image X,Image Y
								Bullet->Width,		Bullet->Height,	//Display Size W,H
								0xff000000);}						//Color transparente}
					else {bulx=0;buly=0;}

					if (door1==1)
					{
						BackImage	(static_cast<int>(ptr3.ToInt32()),Door->Width,		Door->Height,	
								(492-StaticPosX)*scale,(222-StaticPosY)*scale,		//X,Y
								0,0,			//Image X,Image Y
								24,48					//Display Size W,H
								,0xff0080ff);			//Color transparente
					}
					else{
						BackImage	(static_cast<int>(ptr3.ToInt32()),Door->Width,		Door->Height,	
								(500-StaticPosX)*scale,(222-StaticPosY)*scale,		//X,Y
								8,0,			//Image X,Image Y
								16,48					//Display Size W,H
								,0xff0080ff);			//Color transparente
					}
				   bufferGAMB->UnlockBits(bmpData); //unlock bits es necesario para decirle a la maquina que terminamos de usar el bmp y ahora lo puede usar el pictureBox
				   Samus1->UnlockBits(bmpData2);
				   background->UnlockBits(bmpData1);
				   Door->UnlockBits(bmpData3);
				   Samus2->UnlockBits(bmpData4);
				   Bullet->UnlockBits(bmpData5);
			 }

	private: System::Void SwapBufferGAMB()
			 {
				 pictureBox1->Image=bufferGAMB; //Copiamos lo dibujado al pictureBox
			 }
	private: System::Void key_down(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				
				// if(e->KeyCode== Keys::Up)		{k_up=	true;}
				//	 else {k_up=	false;}
				// if(e->KeyCode== Keys::Down)		{ StaticPosY=StaticPosY+3;/*scale--;*/	k_down=	true;}
				//	else {k_down=	false;}
				 if(e->KeyCode== Keys::Left)		{
					 if (stimer>=sdelay){if (sindex0>=2){sindex0=0;}else{sindex0++;}stimer=0;}else{stimer++;}
					 dir=-1; StaticPosX+=-3;k_left=	true;}
					else {k_left=	false;}
				 if(e->KeyCode== Keys::Right)	
				 {if (stimer>=sdelay){if (sindex0>=2){sindex0=0;}else{sindex0++;}stimer=0;}else{stimer++;}
				 if (StaticPosX<=341||StaticPosX>341&&door1==0)
				 { StaticPosX+=3;}
				 dir=1;
				 
				 
				 k_right=true;}
					else {k_right=	false;}
				 if(e->KeyCode== Keys::Space)	{excolor=excolor+0x00050505;k_space=true;}
					else {k_space=	false;}
				if(e->KeyCode== Keys::Z)	{shoot=1; k_z=true;
				//Audio^ sndshoot=new Audio("short_beam.wav");
				//sndshoot->Play();
				}
				 if(e->KeyCode== Keys::Q)scale++;
				 if(e->KeyCode== Keys::W)scale--;
					else { k_z=	false;}
					 if(StaticPosY>600-60)	{StaticPosY=600-60;}
					 if(StaticPosY<0)		{StaticPosY=0;}
					 if(StaticPosX<0)		{StaticPosX=0;}
					 if(StaticPosX>900-20)	{StaticPosX=900-20;}
			 }
};
#pragma unmanaged
	void TabulaRaza(){
		__asm{
			mov ecx, 900*600
			mov edi, surf	
		lazo:
			mov eax, 0x00000000
			mov [edi], eax		
			add edi, 4			
		loop lazo
		}
	}
	void BackImage(int spr, int iw,int ih,int x, int y, int ix, int iy, int w, int h,int trans)
	{int var;
		__asm{
			//x,y
			//posicion de lo que se dibujara 
			mov edi, surf		//EDI se vuelve el apuntador del pixel inicial de la superficie
			mov esi, spr		//y ESI el de la imagen
			mov eax, 4	//
			mul x
			add edi, eax
			mov eax, 4*900//
			mul y
			add edi, eax
			//ix,iy
			//Desplazamiento x en la imagen
			mov eax, 4
			mul ix
			add esi, eax
			//Desplazamiento y en la imagen
			mov eax, 4
			mul iw
			mul iy
			add esi, eax
			mov ecx, h
		lazo2:
			push ecx
			mov ecx, w
			MOV EBX, scale  //EBX es el contador para las veces que se repetira el pixel
			MOV var,EBX		//Fingiendo push
lazo:
			MOV EBX, scale
			SCALEX:				//Inicio del bucle en X
				cmp edi,surf
				jl alpha		
				MOV EAX,4*899*600
				ADD EAX,surf
				CMP EDI,EAX
			JNL ENDPIC			//Inicio de colocacion
			mov eax, [esi]
				cmp eax, trans
			je alpha
				add eax,excolor
			mov eax, [esi]	//Lee el pixel
				mov [edi], eax	//Copia el pixel
			alpha:				//Fin de colocacion
				add edi, 4		//Cambia de pixel
				DEC EBX			//Disminuye el contado
				CMP EBX,0		//Si el contador se termina
			JNE SCALEX			//Sale del programa
				add esi, 4		//Cambia al siguiente pixel de la imagen
		loop lazo
		jmp endapollo
			apollo:
				jmp lazo2
			endapollo:
			mov ebx, 900
			mov eax, w
			mul scale
			sub ebx, eax
			shl ebx, 2
			add edi, ebx//
			mov ebx,var //Finginendo pop
			DEC EBX
			CMP EBX,0
		JE SIGUIENTE
		mov ecx,w
			mov var,ebx	//Fingiendo push
			MOV EBX, scale
			mov eax,4
			mul w
			sub esi,eax
		JMP SCALEX
		SIGUIENTE:
			mov eax, iw
			sub eax, w
			shl eax, 2
			add esi, eax
			pop ecx
		loop apollo
ENDPIC:
		}
	}


#pragma managed
}