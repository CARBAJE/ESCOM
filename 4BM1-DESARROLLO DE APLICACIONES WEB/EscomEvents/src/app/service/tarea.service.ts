import { Injectable } from '@angular/core';
import {HttpClient, HttpHeaders} from '"@angular/common/http';
import { Observable, map } from 'rxjs';
import { Tarea } from '../tareas/tarea';

@Injectable({
  providedIn: 'root'
})
export class TareaService {

  private urlEndPoint: string = '';
  private httpHeaders = new this.httpHeaders({ContentType: 'application/son'});

  constructor(private http : HttpClient) { }

  readAll(): Observable<Tarea[]>
    return this.http.get(this.urlEndPoint).pipe(map((Response) => Response as Tarea[]))
