USE [master]
GO
/****** Object:  Database [bd_tutin]    Script Date: 05-05-2018 13:25:33 ******/
CREATE DATABASE [bd_tutin]
 CONTAINMENT = NONE
 ON  PRIMARY 
( NAME = N'bd_tutint', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL12.MSSQLSERVER\MSSQL\DATA\bd_tutint.mdf' , SIZE = 5120KB , MAXSIZE = UNLIMITED, FILEGROWTH = 1024KB )
 LOG ON 
( NAME = N'bd_tutint_log', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL12.MSSQLSERVER\MSSQL\DATA\bd_tutint_log.ldf' , SIZE = 2048KB , MAXSIZE = 2048GB , FILEGROWTH = 10%)
GO
ALTER DATABASE [bd_tutin] SET COMPATIBILITY_LEVEL = 120
GO
IF (1 = FULLTEXTSERVICEPROPERTY('IsFullTextInstalled'))
begin
EXEC [bd_tutin].[dbo].[sp_fulltext_database] @action = 'enable'
end
GO
ALTER DATABASE [bd_tutin] SET ANSI_NULL_DEFAULT OFF 
GO
ALTER DATABASE [bd_tutin] SET ANSI_NULLS OFF 
GO
ALTER DATABASE [bd_tutin] SET ANSI_PADDING OFF 
GO
ALTER DATABASE [bd_tutin] SET ANSI_WARNINGS OFF 
GO
ALTER DATABASE [bd_tutin] SET ARITHABORT OFF 
GO
ALTER DATABASE [bd_tutin] SET AUTO_CLOSE OFF 
GO
ALTER DATABASE [bd_tutin] SET AUTO_SHRINK OFF 
GO
ALTER DATABASE [bd_tutin] SET AUTO_UPDATE_STATISTICS ON 
GO
ALTER DATABASE [bd_tutin] SET CURSOR_CLOSE_ON_COMMIT OFF 
GO
ALTER DATABASE [bd_tutin] SET CURSOR_DEFAULT  GLOBAL 
GO
ALTER DATABASE [bd_tutin] SET CONCAT_NULL_YIELDS_NULL OFF 
GO
ALTER DATABASE [bd_tutin] SET NUMERIC_ROUNDABORT OFF 
GO
ALTER DATABASE [bd_tutin] SET QUOTED_IDENTIFIER OFF 
GO
ALTER DATABASE [bd_tutin] SET RECURSIVE_TRIGGERS OFF 
GO
ALTER DATABASE [bd_tutin] SET  DISABLE_BROKER 
GO
ALTER DATABASE [bd_tutin] SET AUTO_UPDATE_STATISTICS_ASYNC OFF 
GO
ALTER DATABASE [bd_tutin] SET DATE_CORRELATION_OPTIMIZATION OFF 
GO
ALTER DATABASE [bd_tutin] SET TRUSTWORTHY OFF 
GO
ALTER DATABASE [bd_tutin] SET ALLOW_SNAPSHOT_ISOLATION OFF 
GO
ALTER DATABASE [bd_tutin] SET PARAMETERIZATION SIMPLE 
GO
ALTER DATABASE [bd_tutin] SET READ_COMMITTED_SNAPSHOT OFF 
GO
ALTER DATABASE [bd_tutin] SET HONOR_BROKER_PRIORITY OFF 
GO
ALTER DATABASE [bd_tutin] SET RECOVERY SIMPLE 
GO
ALTER DATABASE [bd_tutin] SET  MULTI_USER 
GO
ALTER DATABASE [bd_tutin] SET PAGE_VERIFY CHECKSUM  
GO
ALTER DATABASE [bd_tutin] SET DB_CHAINING OFF 
GO
ALTER DATABASE [bd_tutin] SET FILESTREAM( NON_TRANSACTED_ACCESS = OFF ) 
GO
ALTER DATABASE [bd_tutin] SET TARGET_RECOVERY_TIME = 0 SECONDS 
GO
ALTER DATABASE [bd_tutin] SET DELAYED_DURABILITY = DISABLED 
GO
USE [bd_tutin]
GO
/****** Object:  Table [dbo].[actividad]    Script Date: 05-05-2018 13:25:33 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[actividad](
	[num_actividad] [int] NOT NULL,
	[IdJugador_act] [varchar](45) NOT NULL,
	[nombre_hab] [varchar](45) NOT NULL,
	[buenas] [int] NOT NULL,
	[malas] [int] NOT NULL,
	[niv_logro_acti] [varchar](45) NOT NULL,
	[cant_estrellas] [int] NOT NULL,
	[intentos] [int] NOT NULL,
	[dificultad] [varchar](45) NOT NULL,
	[complejidad] [varchar](45) NOT NULL,
	[codigo_act] [int] NOT NULL,
	[num_sesion] [int] NOT NULL,
	[problema] [text] NULL,
	[regla_actuacion] [text] NOT NULL,
 CONSTRAINT [PK_actividad] PRIMARY KEY CLUSTERED 
(
	[codigo_act] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[habilidad]    Script Date: 05-05-2018 13:25:33 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[habilidad](
	[nombre_hab] [varchar](45) NOT NULL,
	[IdJugador_hab] [varchar](45) NOT NULL,
	[nom_niv] [varchar](45) NOT NULL,
	[niv_logro_hab] [varchar](45) NOT NULL,
	[cant_estrellas] [int] NOT NULL,
	[permiso] [varchar](45) NOT NULL,
	[contador_alto] [int] NOT NULL,
	[contador_medio] [int] NOT NULL,
	[contador_bajo] [int] NOT NULL
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[jugador]    Script Date: 05-05-2018 13:25:33 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[jugador](
	[nom_jugador] [varchar](45) NOT NULL,
	[total_estrellas] [int] NOT NULL,
 CONSTRAINT [PK_jugador] PRIMARY KEY CLUSTERED 
(
	[nom_jugador] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[nivel]    Script Date: 05-05-2018 13:25:33 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[nivel](
	[nom_nivel] [varchar](45) NOT NULL,
	[IdJugador_nivel] [varchar](45) NOT NULL,
	[cant_estrellas] [int] NOT NULL,
	[permiso] [varchar](45) NOT NULL
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[objetivos]    Script Date: 05-05-2018 13:25:33 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[objetivos](
	[habilidad] [varchar](50) NULL,
	[dificultad] [varchar](45) NULL,
	[complejidad] [varchar](45) NULL,
	[num_actividad] [varchar](45) NULL,
	[objetivo] [text] NULL
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[percepciones]    Script Date: 05-05-2018 13:25:33 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[percepciones](
	[tiempo_actividad] [time](7) NOT NULL,
	[cant_ayuda] [int] NOT NULL,
	[porcentaje_actuacion] [float] NOT NULL,
	[num_actividad] [varchar](45) NOT NULL,
	[codigo_percepciones] [int] NOT NULL,
	[nivel_actuacion] [varchar](45) NOT NULL,
	[total_actuacion] [varchar](45) NOT NULL,
 CONSTRAINT [PK_percepciones] PRIMARY KEY CLUSTERED 
(
	[codigo_percepciones] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[tiempo_item]    Script Date: 05-05-2018 13:25:33 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[tiempo_item](
	[codigo_tr] [int] NOT NULL,
	[num_item] [int] NOT NULL,
	[tiempo] [time](7) NOT NULL
) ON [PRIMARY]

GO
ALTER TABLE [dbo].[actividad]  WITH CHECK ADD  CONSTRAINT [FK_actividad_jugador] FOREIGN KEY([IdJugador_act])
REFERENCES [dbo].[jugador] ([nom_jugador])
GO
ALTER TABLE [dbo].[actividad] CHECK CONSTRAINT [FK_actividad_jugador]
GO
ALTER TABLE [dbo].[actividad]  WITH CHECK ADD  CONSTRAINT [FK_actividad_percepciones] FOREIGN KEY([codigo_act])
REFERENCES [dbo].[percepciones] ([codigo_percepciones])
GO
ALTER TABLE [dbo].[actividad] CHECK CONSTRAINT [FK_actividad_percepciones]
GO
ALTER TABLE [dbo].[habilidad]  WITH CHECK ADD  CONSTRAINT [FK_habilidad_jugador] FOREIGN KEY([IdJugador_hab])
REFERENCES [dbo].[jugador] ([nom_jugador])
GO
ALTER TABLE [dbo].[habilidad] CHECK CONSTRAINT [FK_habilidad_jugador]
GO
ALTER TABLE [dbo].[nivel]  WITH CHECK ADD  CONSTRAINT [FK_nivel_jugador] FOREIGN KEY([IdJugador_nivel])
REFERENCES [dbo].[jugador] ([nom_jugador])
GO
ALTER TABLE [dbo].[nivel] CHECK CONSTRAINT [FK_nivel_jugador]
GO
ALTER TABLE [dbo].[tiempo_item]  WITH CHECK ADD  CONSTRAINT [FK_tiempo_item_actividad] FOREIGN KEY([codigo_tr])
REFERENCES [dbo].[actividad] ([codigo_act])
GO
ALTER TABLE [dbo].[tiempo_item] CHECK CONSTRAINT [FK_tiempo_item_actividad]
GO
USE [master]
GO
ALTER DATABASE [bd_tutin] SET  READ_WRITE 
GO
