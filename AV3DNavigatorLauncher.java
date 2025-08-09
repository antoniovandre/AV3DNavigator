/*
 * Proprietário: Antonio Vandré Pedrosa Furtunato Gomes.
 * 
 * Launcher do software AV3DNavigator.
 * 
 * Dependências: AntonioVandre.
 * 
 * Sugestões ou comunicar erros: "a.vandre.g@gmail.com".
 * 
 * Licença de uso: Creative Commons Attribution Non-Commercial License V2.0.
 * 
 * Última atualização: 09-08-2025.
 */

import java.awt.Toolkit;
import java.awt.image.BufferedImage;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.GradientPaint;
import java.awt.BorderLayout;
import java.awt.Paint;
import java.awt.Color;
import java.awt.Font;

import javax.imageio.ImageIO;
import javax.swing.ImageIcon;
import javax.swing.JWindow;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.WindowConstants;
import javax.swing.border.EmptyBorder;

import java.net.URL;

import java.lang.ProcessBuilder;

import java.io.*;

public class AV3DNavigatorLauncher
	{
	public static String VersaoLauncher = "09-08-2025";

	public static String URL3DNavigatorVersao = "https://github.com/antoniovandre/AV3DNavigator/raw/main/AV3DNavigatorVersao.txt";

	public static String ArquivoAV3DNavigatorVersao = "AV3DNavigatorVersao.txt";

	public static String URLAV3DNavigatorInstallList = "https://github.com/antoniovandre/AV3DNavigator/raw/main/AV3DNavigatorInstallList.txt";

	public static String ArquivoAV3DNavigatorInstallList = "AV3DNavigatorInstallList.txt";

	public static String URLapfloat = "https://github.com/antoniovandre/AV3DNavigator/raw/main/apfloat.jar";

	public static String URLmXparser = "https://github.com/antoniovandre/AV3DNavigator/raw/main/MathParser.org-mXparser.jar";

	public static String MensagemErroAtualizar = "Erro ao atualizar o AV3DNavigator.";

	public static String MensagemErroExecutar = "Erro ao executar AV3DNavigator. Pode ser perda de conexão com a internet.";

	public class SplashScreen {

		public static final JWindow SPLASH_SCREEN;

		static {SPLASH_SCREEN = new JWindow();}

		public static void show() {
			BufferedImage Img;
			try {Img = ImageIO.read(AV3DNavigatorLauncher.class.getResourceAsStream("AV3DNavigator - SplashScreen.png"));} catch (IOException e) {return;}
			Dimension Screen = Toolkit.getDefaultToolkit().getScreenSize();
			SPLASH_SCREEN.setBounds((int) (Screen.width - Img.getWidth()) / 2, (int) (Screen.height - Img.getHeight()) / 2, Img.getWidth(), Img.getHeight());
			SPLASH_SCREEN.setBackground(new Color(0, 0, 0, 0));
			SPLASH_SCREEN.add(new JLabel(new ImageIcon(Img)) , BorderLayout.CENTER);
			SPLASH_SCREEN.setVisible(true);
		}

		public static void close() {
			SPLASH_SCREEN.dispose();
		}
	}

	public class GradientLabel extends JLabel
		{
		private Color CorInicial;
		private Color CorFinal;

		public GradientLabel(String Texto)
			{
			super(Texto);

			CorInicial = Color.BLUE;
			CorFinal = Color.BLACK;
			this.setForeground(Color.WHITE);
			}

		public GradientLabel(String Texto, Color CorInicial, Color CorFinal)
			{
			super(Texto);
			this.CorInicial = CorInicial;
			this.CorFinal = CorFinal;
			this.setForeground(Color.WHITE);
			}

		public GradientLabel(String Texto, Color CorInicial, Color CorFinal, Color CorForeground)
			{
			super(Texto);
			this.CorInicial = CorInicial;
			this.CorFinal = CorFinal;
			this.setForeground(CorForeground);
			}

		public void paint(Graphics g)
			{
			int width = getWidth();
			int height = getHeight();

			GradientPaint paint = new GradientPaint(0, 0, CorInicial, width, height, CorFinal, true);
			Graphics2D g2d = (Graphics2D) g;
			Paint oldPaint = g2d.getPaint();
			g2d.setPaint(paint);
			g2d.fillRect(0, 0, width, height);
			g2d.setPaint(oldPaint);
			super.paint(g);
			}
		}

	public static void main (String[] args) {AV3DNavigatorLauncher mainc = new AV3DNavigatorLauncher(); mainc.mainrun(args);}

	public void mainrun(String[] args)
		{
		int FlagSucessoDownloadNet = 1;

		SplashScreen.show();

		try
			{
			downloadUsingStream(URL3DNavigatorVersao, ArquivoAV3DNavigatorVersao + ".tmp");
			} catch (IOException e) {FlagSucessoDownloadNet = 0;}

		if (FlagSucessoDownloadNet == 1)
			{
			File file = new File(ArquivoAV3DNavigatorVersao);
			int FlagSucessoVersaoLocal = 1;
			String VersaoLocal = "";

			try
				{
				BufferedReader br = new BufferedReader(new FileReader(file));

				do {VersaoLocal = br.readLine();} while (((VersaoLocal.replaceAll(" ", "").equals(""))) || (VersaoLocal.replaceAll(" ", "").charAt(0) == '#'));

				} catch (IOException e) {FlagSucessoVersaoLocal = 0;}

			File fileNet = new File(ArquivoAV3DNavigatorVersao + ".tmp");
			File fileList = new File(ArquivoAV3DNavigatorInstallList);
			int FlagSucessoVersaoNet = 1;
			String VersaoNet = "";
			String Lista = "";

			try
				{
				BufferedReader brNet = new BufferedReader(new FileReader(fileNet));

				do {VersaoNet = brNet.readLine();} while (((VersaoNet.replaceAll(" ", "").equals(""))) || (VersaoNet.replaceAll(" ", "").charAt(0) == '#'));
				} catch (IOException e) {FlagSucessoVersaoNet = 0;}

			if ((FlagSucessoVersaoLocal == 1) && (FlagSucessoVersaoNet == 1))
				{
				if (! (VersaoNet.equals(VersaoLocal)))
					{
					try
						{
						downloadUsingStream(URL3DNavigatorVersao, ArquivoAV3DNavigatorVersao);

						downloadUsingStream(URLAV3DNavigatorInstallList, ArquivoAV3DNavigatorInstallList);

						BufferedReader brL = new BufferedReader(new FileReader(fileList));

						do {Lista = brL.readLine(); if (Lista != null) if (! ((Lista.replaceAll(" ", "").equals("")) || (Lista.replaceAll(" ", "").charAt(0) == '#'))) downloadUsingStream(Lista.split(",")[0], Lista.split(",")[1]);} while (Lista != null);
						} catch (IOException e) {}

					/* Mostrar aviso de atualização.

					JFrame Frame = new JFrame("Nova versão.");
					Frame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
					Frame.setPreferredSize(new Dimension(320, 130));
					GradientLabel Label = new GradientLabel("<html>O software foi atualizado.</html>", Color.BLUE, Color.BLACK, Color.WHITE);
					Label.setBorder(new EmptyBorder(5, 5, 5, 5));
					Label.setFont(new Font("DialogInput", Font.BOLD | Font.ITALIC, 12));
					Frame.add(Label);
					Frame.pack();
					Frame.setVisible(true);
					*/
					}
				}
			else
				try
					{
					downloadUsingStream(URLAV3DNavigatorInstallList, ArquivoAV3DNavigatorInstallList);

					BufferedReader brL = new BufferedReader(new FileReader(fileList));

					do {Lista = brL.readLine(); if (Lista != null) if (! ((Lista.replaceAll(" ", "").equals("")) || (Lista.replaceAll(" ", "").charAt(0) == '#'))) downloadUsingStream(Lista.split(",")[0], Lista.split(",")[1]);} while (Lista != null);
					} catch (IOException e) {}
			}

		try
			{
			String ArquivoEspaco = "";
			String Debug = "";
			ProcessBuilder pb = null;

			if (args.length == 2) {ArquivoEspaco = args[0]; Debug = args[1]; pb = new ProcessBuilder("java", "-jar", "AV3DNavigator.jar", ArquivoEspaco, Debug);} else if (args.length == 1) {if (args[0].equals("Debug")) pb = new ProcessBuilder("java", "-jar", "AV3DNavigator.jar", "Debug"); else {ArquivoEspaco = args[0]; pb = new ProcessBuilder("java", "-jar", "AV3DNavigator.jar", ArquivoEspaco, "");}} else pb = new ProcessBuilder("java", "-jar", "AV3DNavigator.jar", "", "");

			SplashScreen.close();
			Process p = pb.start();
			} catch (IOException e)
				{
				File file = new File(ArquivoAV3DNavigatorVersao);
				file.delete();
				System.out.println(MensagemErroExecutar);
				}
		}

	private static void downloadUsingStream(String urlStr, String file) throws IOException
		{
		URL url = new URL (urlStr);
		BufferedInputStream bis = new BufferedInputStream (url.openStream ());
		FileOutputStream fis = new FileOutputStream (file);
		byte [] buffer = new byte [1024];
		int count = 0;
		while((count = bis.read (buffer, 0, 1024)) != -1) {fis.write(buffer, 0, count);}
		fis.close(); bis.close();
		}
}
