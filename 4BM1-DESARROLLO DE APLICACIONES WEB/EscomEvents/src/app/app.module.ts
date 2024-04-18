import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { HeaderComponent } from './header/header.component';
import { FooterComponent } from './footer/footer.component';
import { ContenidoComponent } from './contenido/contenido.component';
import { OperacionesComponent } from './operaciones/operaciones.component';
import { HomeComponent } from './home/home.component';
import { TareasComponent } from './tareas/tareas.component';

@NgModule({
  declarations: [
    AppComponent,
    HeaderComponent,
    FooterComponent,
    ContenidoComponent,
    OperacionesComponent,
    HomeComponent,
    TareasComponent
  ],
  imports: [
    BrowserModule,
    AppRoutingModule
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
