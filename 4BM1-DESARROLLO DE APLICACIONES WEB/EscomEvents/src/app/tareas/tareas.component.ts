import { Component, OnInit } from '@angular/core';
import { Tarea } from './tarea';
import { TareaService } from '../service/tarea.service';
import Swal from 'sweetalert2';

@Component({
  selector: 'app-tareas',
  templateUrl: './tareas.component.html',
  styleUrls: ['./tareas.component.css']
})
export class TareasComponent implements OnInit {

  constructor(private tareaService: TareaService){}

  ngOnInit(): void{
    this-this.tareaService.readAll().subscribe((tareas) => )
  }

  ListaDeTareas : Tarea[] = [
    {
      id : 1,
      nombreTarea : 'Repasar JS',
      estado : true
    },
    {
      id : 2,
      nombreTarea : "Aprender Spring",
      estado : false
    },
    {
      id : 3,
      nombreTarea : "Conquistar el mundo",
      estado : false
    },
    {
      id : 4,
      nombreTarea : "Destruir el mundo",
      estado : false
    },
    {
      id : 5,
      nombreTarea : "Estudia Examen",
      estado : true
    }
  ]
  ngOnInit(): void {
    throw new Error('Method not implemented.');
  }

  eliminar(tarea: Tarea): void{
    console.log("Tarea eliminada: "+tarea.nombreTarea);
    Swal.fire({
      title: "Are you sure?",
      text: "You won't be able to revert this!",
      icon: "warning",
      showCancelButton: true,
      confirmButtonColor: "#3085d6",
      cancelButtonColor: "#d33",
      confirmButtonText: "Yes, delete it!"
    }).then((result) => {
      if (result.isConfirmed) {
        Swal.fire({
          title: "Deleted!",
          text: "Your file has been deleted.",
          icon: "success"
        });
      }
    });
  }
}